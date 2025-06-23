#include "States/StateStack.h"

#include "States/State.h"
#include "States/Stages/DayMountainStage.h"
#include "States/Stages/NightMountainStage.h"
#include "States/Menus/PausedState.h"
#include "States/Menus/MenuState.h"
#include "States/Menus/EndMenu.h"
#include "States/Menus/Leaderboard.h"

#include <iostream>

namespace States {
  StateStack* StateStack::pSelf(NULL);

  StateStack::StateStack()
    : stack()
    , commandQueue()
  {
    
  }

  void StateStack::createState(StateType stateType, State* pState) {
    State* state = NULL;

    switch (stateType) {
      case (StateType::Menu): 
        state = new MenuState; 
        break;
      case (StateType::GameDay):
        state = new DayMountainStage;
        break;
      case (StateType::GameNight):
        state = new NightMountainStage;
        break;
      case (StateType::Paused):
        state = pState;
        break;
      case (StateType::EndMenu):
        state = pState;
        break;
      case (StateType::Leaderboard):
        state = new Leaderboard;
        break;
      case (StateType::LoadGame): {
        std::ifstream file("../data/save.json");
        json jsonData = json::parse(file);
        std::vector<json> data = jsonData.get<std::vector<json>>();
        if (data[0]["map"] == "day") {
          state = new DayMountainStage(false);
        }
        else if (data[0]["map"] == "night") {
          state = new NightMountainStage(false);
        }
      }
        
        
      /*case (StateType::PlayerSelect): 
        state = new PlayerSelectState; 
        break;
      case (StateType::StageSelect): 
        state = new StageSelectState; 
        break;
      case (StateType::Loading):
        state = new LoadingState;
        break;*/
      
      /*case (StateType::Continue):
        state = new LoadingState(false);
        break;
      
      case (StateType::SaveScore):
        state = new SaveScoreState;
        break;
      */
      default:
        break;
    }

    if (!state) {
      std::cerr << "Error creating " << static_cast<int>(stateType) << " state! \n";
      return;
    }

    if (stack.size() > 0)
      stack.back()->setIsActive(false);

    stack.push_back(state);
  }

  StateStack::~StateStack() {
    clearStates();
  }

  StateStack* StateStack::getInstance() {
    if (pSelf == NULL)
      pSelf = new StateStack;
    return pSelf;
  }

  void StateStack::pushState(StateType stateType, State* pState, const bool isReplacing) {
    Command command = Command::Push;

    if (isReplacing)
      command = Command::Clear;

    commandQueue.push(CommandDetails{command, stateType, pState});
  }

  void StateStack::popState() {
    commandQueue.push(CommandDetails{Command::Pop, StateType::TotalStates, NULL});
  }

  void StateStack::delayedPopState() {
    States::State* tmpState = stack.back();
    delete tmpState;
    stack.erase(stack.end() - 1);

    if (stack.size() > 0)
      stack.back()->setIsActive(true);
  }

  void StateStack::clearStates() {
    std::vector<State*>::iterator it = stack.begin();

    while (it != stack.end()) {
      delete *it;
      ++it;
    } 

    stack.clear(); 
  }

  void StateStack::applyPendingCommands() {
    while (!commandQueue.empty()) {
      CommandDetails cmd = commandQueue.front();

      switch (cmd.command) {
        case (Command::Push):
          createState(cmd.stateType, cmd.pState);
          break;
        case (Command::Pop):
          delayedPopState();
          break;
        case (Command::Clear):
          clearStates();
          createState(cmd.stateType, cmd.pState);
          break;
        default:
          break;
      }
      
      commandQueue.pop();
    }
  }

  State* StateStack::getBack() const {
    return stack.back();
  }

  void StateStack::exec() {
    applyPendingCommands();

    if (!stack.empty()) {
      stack.back()->exec();
    }
  }

}
//Class adapted from the game ASCENT, github repository: https://github.com/0x4D4453/ASCENT

#pragma once

#include <SFML/Graphics.hpp>

#include <stack>
#include <queue>

namespace States {
    enum class StateType;
    class State;
}

namespace States {
  class StateStack : public sf::NonCopyable {
    private:
      enum class Command {
        Push,
        Pop,
        Clear,
        TotalCommands
      };
    
    private:
      struct CommandDetails {
        Command command;
        StateType stateType;
        State* pState;
      };

    private:
      static StateStack* pSelf;
      std::stack<State*> stack;
      std::queue<CommandDetails> commandQueue;

    private:
      StateStack();
      void createState(StateType stateType, State* pState);
      void delayedPopState();
      void clearStates();
      void applyPendingCommands();
  
    public:
      ~StateStack();
      static StateStack* getInstance();
      void pushState(StateType stateType, State* pState = NULL, const bool isReplacing = false);
      void popState();
      void exec();
  };
}

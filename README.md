# SmartVacuumAgent
A C++ simulation of a simple reflex-based vacuum cleaner agent. The agent operates in a grid-like environment consisting of three rooms, identified as A, B, and C. Each room can either be dirty or clean, and the agent moves between rooms to clean them based on a set of predefined reflex rules.

The agent's actions are determined by the current state of the room (dirty or clean) and its position. If the room is dirty, the agent sucks the dirt. If the room is clean, it moves to the next room based on a logical movement pattern. The environment randomly resets after all rooms are clean to simulate continuous operation.

# Features:
- Reflex-based decision-making model for the vacuum cleaner agent.
- Randomized environment setup for room cleanliness.
- Interactive console-based interface with visual representation of the environment.
- Simple simulation loop allowing the agent to clean and reset the environment dynamically.
  
This project is an educational implementation demonstrating basic concepts of artificial intelligence and agent-based systems.

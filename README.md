# Philosophers

## Introduction
Philosophers is a project that introduces the basics of threading and synchronization using mutexes. The goal is to simulate the classic dining philosophers problem, ensuring that philosophers can eat, think, and sleep without encountering race conditions or deadlocks.

## How It Works
- A number of philosophers sit at a round table with a bowl of spaghetti in the center.
- Each philosopher alternates between eating, thinking, and sleeping.
- To eat, a philosopher must pick up two forks (one on their left and one on their right).
- If a philosopher cannot acquire both forks, they must wait.
- The simulation continues until a philosopher starves (if not properly managed) or a defined number of meals is reached.

## Project Specifications
- Implemented in C.
- Uses threads (`pthread_create`, `pthread_join`) and mutexes (`pthread_mutex_lock`, `pthread_mutex_unlock`) for synchronization.
- Logs each philosopher's actions with precise timestamps.
- The simulation stops when a philosopher dies of starvation or when all philosophers have eaten a specified number of times.

## Compilation & Execution
### Compilation
```sh
make
```
### Execution
```sh
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
- `number_of_philosophers`: Number of philosophers (and forks).
- `time_to_die`: Time in milliseconds after which a philosopher dies if they don’t eat.
- `time_to_eat`: Time in milliseconds taken to eat.
- `time_to_sleep`: Time in milliseconds spent sleeping.
- `number_of_times_each_philosopher_must_eat` (optional): If set, the simulation ends when all philosophers eat at least this many times.

## Example
```sh
./philo 5 800 200 200
```
This runs the simulation with 5 philosophers, where each must eat before 800ms to avoid starvation, takes 200ms to eat, and sleeps for 200ms before thinking.

## Rules & Constraints
- No global variables are allowed.
- No memory leaks or segmentation faults.
- The output must be correctly formatted and without race conditions.

## Contact
For any questions or inquiries, please contact the repository owner at anamieta@student.42heilbronn.de.

**Note:** This repository is part of the 42 school curriculum and contains exercises designed to teach and test various multithreading and synchronization concepts.

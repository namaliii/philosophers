# [1;34mPhilosophers[0m

## [1;32mIntroduction[0m

Philosophers is a project that introduces the basics of threading and synchronization using mutexes. The goal is to simulate the classic dining philosophers problem, ensuring that philosophers can eat, think, and sleep without encountering race conditions or deadlocks.

## [1;32mHow It Works[0m

- A number of philosophers sit at a round table with a bowl of spaghetti in the center.
- Each philosopher alternates between [1;33meating[0m, [1;33mthinking[0m, and [1;33msleeping[0m.
- To eat, a philosopher must pick up two forks (one on their left and one on their right).
- If a philosopher cannot acquire both forks, they must wait.
- The simulation continues until a philosopher starves (if not properly managed) or a defined number of meals is reached.

## [1;32mProject Specifications[0m

- Implemented in [1;36mC[0m.
- Uses threads (`pthread_create`, `pthread_join`) and mutexes (`pthread_mutex_lock`, `pthread_mutex_unlock`) for synchronization.
- Logs each philosopher's actions with precise timestamps.
- The simulation stops when a philosopher dies of starvation or when all philosophers have eaten a specified number of times.

## [1;32mCompilation & Execution[0m

### [1;35mCompilation[0m

```sh
make
```

### [1;35mExecution[0m

```sh
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

- `[1;33mnumber_of_philosophers[0m`: Number of philosophers (and forks).
- `[1;33mtime_to_die[0m`: Time in milliseconds after which a philosopher dies if they don’t eat.
- `[1;33mtime_to_eat[0m`: Time in milliseconds taken to eat.
- `[1;33mtime_to_sleep[0m`: Time in milliseconds spent sleeping.
- `[1;33mnumber_of_times_each_philosopher_must_eat[0m` (optional): If set, the simulation ends when all philosophers eat at least this many times.

## [1;32mExample[0m

```sh
./philo 5 800 200 200
```

This runs the simulation with 5 philosophers, where each must eat before [1;33m800ms[0m to avoid starvation, takes [1;33m200ms[0m to eat, and sleeps for [1;33m200ms[0m before thinking.

## [1;32mRules & Constraints[0m

- No [1;31mglobal variables[0m are allowed.
- No [1;31mmemory leaks[0m or [1;31msegmentation faults[0m.
- The output must be correctly formatted and without race conditions.

## [1;32mContact[0m

For any questions or inquiries, please contact the repository owner at [anamieta@student.42heilbronn.de](mailto:anamieta@student.42heilbronn.de).

**Note:** This repository is part of the 42 school curriculum and contains exercises designed to teach and test various multithreading and synchronization concepts.


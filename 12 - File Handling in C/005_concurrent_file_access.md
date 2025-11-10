## Problem 5: How do you handle concurrent access to the same file by multiple C programs? Discuss file locking mechanisms available in C and their limitations on different platforms.

### Answer
- Use file locking to coordinate access.
- Two main types: Advisory and Mandatory locking.
- Advisory locking – programs cooperate and respect locks voluntarily.
- Implemented using flock() (whole file) or fcntl() (region-based).
- Mandatory locking – OS enforces locks; other processes are blocked automatically.
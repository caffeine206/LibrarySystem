# SHHH LIBRARY SYSTEM DOCUMENTATION
By Sota Ogo, Derek Willms

## Software architecture
We used MVC + Router as our software architecture. We utilize singleton to keep the data consitancy (Singleton shouldn't be use in a real project for data storing; however, our assumption is that this library system won't be operated by multiple people at the same time.).

# Folder structure
```
.
├
├── Collections // Collections
├── Controller	// Controllers
├── lib 		// Utilities, Router, Request
│   └── Request // Request
├── Model 		// Models
│   └── Book 	// Books
├── tests 		// Test specs for Unit test
└── View 		// Views
```

## Explanation

### Compile && execution
```
make clean
make
./shhh data4books.txt data4patrons.txt < data4commands.txt
```

### Class diagram
Please refer classdiagram.pdf to see our class design.

### Data structure
We use Binary tree for book sorting, and Hash Table for searching. For history, we use linked list to keep track of user history.

### Basic flow
1. Everything starts from Router. View or main.cpp uses Router, in order to call controller.
2. Controller updates the state of the software (Views and Models).

### Controller
In controller, we implemented actions such as checkout, return, and display.

### Model
Models represents all kinds of data (User, Book, History)

### Collection
Collection represents a set of models. There are "Indexed" and "UnIndexed" for collections. They have different data structures.

### View
View represents the system states. Any kinds of output except errors are generated in View.

### Router
Router manages which controller to be called from user command.

### Request
Request is a data parser utility. It allows classes (Controller, View, Model) to have the same language (input structure).

### Catch
Catch is a testing framework for c++. We used it for our unit testing.

## Other assumption

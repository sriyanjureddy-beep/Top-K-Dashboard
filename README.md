Top-K Best Selling Products Dashboard

A C++ Data Structures and Algorithms project designed to manage e-commerce product records and identify the Top-K best-selling products using efficient data structures and algorithms.

## Project Overview

The Top-K Best Selling Products system simulates a product management solution for an e-commerce platform. It allows users to manage product information, analyze sales performance, and identify the highest-selling products.

The project demonstrates the practical implementation of **Heap, Hashing, and Merge Sort** to solve real-world product management and ranking problems.

## Key Features

- **Product Management:** Add, update, delete, and display product records.
- **Top-K Best Sellers:** Identify the K highest-selling products using a Max Heap.
- **Dynamic Priority Updates:** Increase or decrease product sales priority and maintain heap order.
- **Hashing:** Search products efficiently using Product IDs.
- **Sorting:** Sort products by sales, price, and product name using Merge Sort.
- **Search and Filtering:** Search by Product ID, name, and category; filter by category, name, sales range, and price range.
- **Sample Data Management:** Load or reset the sample product dataset.
- **Operation History:** Maintain a record of performed operations.
- **Complexity Analysis:** Display the time and space complexity of major operations.
- **Input Validation:** Handle invalid product details and Top-K values.

## Data Structures and Algorithms Used

| Data Structure / Algorithm | Application |
|---|---|
| Max Heap | Finding Top-K best-selling products |
| Hash Table | Product lookup using Product ID |
| Merge Sort | Sorting products by sales, price, and name |
| Vector | Storing and managing product records |
| Linear Search | Searching and filtering product records |

## Technology Stack

- **Programming Language:** C++
- **Core Concepts:** Data Structures and Algorithms
- **STL:** Vector, String, and other C++ standard library utilities
- **Development Environment:** Visual Studio Code

## Sample Dataset

The project includes 15 sample e-commerce product records with information such as:

- Product ID
- Product Name
- Category
- Sales
- Price

Users can also add their own product records.

## How to Run the Project

### 1. Clone the Repository

```bash
git clone https://github.com/sriyanjureddy-beep/Top-K-Dashboard.git
```

### 2. Navigate to the Project Directory

```bash
cd Top-K-Dashboard
```

### 3. Compile the C++ Program

```bash
g++ main.cpp -o main
```

### 4. Run the Program

**Windows:**
```bash
main.exe
```

**Linux / macOS:**
```bash
./main
```

## Project Objective

The primary objective of this project is to understand how different data structures and algorithms can be applied to practical e-commerce scenarios. It focuses on efficient product ranking, searching, sorting, and dynamic data management.

## Future Enhancements

- Develop an interactive web-based dashboard.
- Integrate the C++ backend with a frontend interface.
- Add visual representations of heap operations.
- Introduce interactive charts for product sales analysis.
- Improve data storage and management.

## Author

**Sriyan Jureddy**

GitHub: [@sriyanjureddy-beep](https://github.com/sriyanjureddy-beep)

---

*Built as a practical Data Structures and Algorithms project focused on solving an e-commerce product ranking problem.*

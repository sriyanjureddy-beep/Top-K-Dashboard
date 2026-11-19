
#include <bits/stdc++.h>
using namespace std;


struct Product {
    string id;
    string name;
    int sales;
    double price;
    string category;
};

vector<string> operationHistory;



void addHistory(string operation) {
    operationHistory.push_back(operation);
}

string toLowerCase(string str) {
    for (char &ch : str) {
        ch = tolower(static_cast<unsigned char>(ch));
    }
    return str;
}

bool isBlank(string str) {
    return str.find_first_not_of(" \t\n\r") == string::npos;
}

void display(const vector<Product>& products) {

    if (products.empty()) {
        cout << "No products available.\n";
        return;
    }

    cout << "\n========== PRODUCT DETAILS ==========\n";

    for (const auto &p : products) {
        cout << "\nProduct ID: " << p.id << endl;
        cout << "Product Name: " << p.name << endl;
        cout << "Sales: " << p.sales << endl;
        cout << "Price: " << p.price << endl;
        cout << "Category: " << p.category << endl;
        cout << "----------------------------------\n";
    }
}
void displayHeap(const vector<Product>& heap) {

    cout << "\n========== MAX HEAP ==========\n";

    for (int i = 0; i < (int)heap.size(); i++) {

        cout << "ID: " << heap[i].id
             << " | Name: " << heap[i].name
             << " | Sales: " << heap[i].sales << endl;
    }

    cout << "==============================\n";
}
// ==================== OPERATION HISTORY ====================

void showOperationHistory() {

    cout << "\n===== OPERATION HISTORY =====\n";

    if (operationHistory.empty()) {
        cout << "No operations performed yet.\n";
        return;
    }

    for (int i = 0; i < operationHistory.size(); i++) {
        cout << i + 1 << ". " << operationHistory[i] << endl;
    }
}

// ==================== ADD PRODUCT ====================

void addProduct(vector<Product>& products) {

    Product product;

    cout << "Enter Product ID: ";
    getline(cin, product.id);

    if (isBlank(product.id)) {
        cout << "Product ID cannot be empty!\n";
        return;
    }

    for (const auto &p : products) {
        if (p.id == product.id) {
            cout << "Product ID already exists!\n";
            return;
        }
    }

    cout << "Enter Product Name: ";
    getline(cin, product.name);

    if (isBlank(product.name)) {
        cout << "Product Name cannot be empty!\n";
        return;
    }

    cout << "Enter Category: ";
    getline(cin, product.category);

    if (isBlank(product.category)) {
        cout << "Category cannot be empty!\n";
        return;
    }

    cout << "Enter Sales: ";

    if (!(cin >> product.sales)) {
        cout << "Invalid sales input!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (product.sales < 0) {
        cout << "Sales cannot be negative!\n";
        return;
    }

    cout << "Enter Price: ";

    if (!(cin >> product.price)) {
        cout << "Invalid price input!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (!isfinite(product.price) || product.price <= 0) {
        cout << "Price must be greater than zero!\n";
        return;
    }

    products.push_back(product);

    addHistory("Product " + product.id + " added successfully.");

    cout << "Product added successfully!\n";
}

// ==================== UPDATE PRODUCT ====================

void updateProduct(vector<Product>& products) {

    string id;

    cout << "Enter Product ID to update: ";
    getline(cin, id);

    for (int i = 0; i < products.size(); i++) {

        if (products[i].id == id) {

            cout << "\n1. Product Name\n";
            cout << "2. Category\n";
            cout << "3. Sales\n";
            cout << "4. Price\n";
            cout << "5. Cancel\n";
            cout << "Enter your choice: ";

            int choice;

            if (!(cin >> choice)) {
                cout << "Invalid choice!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (choice) {

                case 1: {
                    string newName;

                    cout << "Enter new Product Name: ";
                    getline(cin, newName);

                    if (isBlank(newName)) {
                        cout << "Product Name cannot be empty!\n";
                        return;
                    }

                    products[i].name = newName;
                    addHistory("Product " + id + " name updated.");

                    cout << "Product Name updated successfully!\n";
                    break;
                }

                case 2: {
                    string newCategory;

                    cout << "Enter new Category: ";
                    getline(cin, newCategory);

                    if (isBlank(newCategory)) {
                        cout << "Category cannot be empty!\n";
                        return;
                    }

                    products[i].category = newCategory;
                    addHistory("Product " + id + " category updated.");

                    cout << "Category updated successfully!\n";
                    break;
                }

                case 3: {
                    int newSales;

                    cout << "Enter new Sales: ";

                    if (!(cin >> newSales)) {
                        cout << "Invalid sales input!\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        return;
                    }

                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    if (newSales < 0) {
                        cout << "Sales cannot be negative!\n";
                        return;
                    }

                    products[i].sales = newSales;
                    addHistory("Product " + id + " sales updated.");

                    cout << "Sales updated successfully!\n";
                    break;
                }

                case 4: {
                    double newPrice;

                    cout << "Enter new Price: ";

                    if (!(cin >> newPrice)) {
                        cout << "Invalid price input!\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        return;
                    }

                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    if (!isfinite(newPrice) || newPrice <= 0) {
                        cout << "Price must be greater than zero!\n";
                        return;
                    }

                    products[i].price = newPrice;
                    addHistory("Product " + id + " price updated.");

                    cout << "Price updated successfully!\n";
                    break;
                }

                case 5:
                    cout << "Update cancelled.\n";
                    return;

                default:
                    cout << "Invalid choice!\n";
                    return;
            }

            return;
        }
    }

    cout << "Product ID not found!\n";
}

// ==================== DELETE PRODUCT ====================

void deleteProduct(vector<Product>& products) {

    string id;

    cout << "Enter Product ID to delete: ";
    getline(cin, id);

    for (int i = 0; i < products.size(); i++) {

        if (products[i].id == id) {

            string productName = products[i].name;

            products.erase(products.begin() + i);

            addHistory("Product " + id + " (" + productName + ") deleted.");

            cout << "Product deleted successfully!\n";
            return;
        }
    }

    cout << "Product ID not found!\n";
}

// ==================== SEARCH PRODUCT ====================

void searchProduct(vector<Product>& products) {

    int choice;

    cout << "\n===== SEARCH PRODUCT =====\n";
    cout << "1. Search by Product ID\n";
    cout << "2. Search by Product Name\n";
    cout << "3. Search by Category\n";
    cout << "Enter your choice: ";

    if (!(cin >> choice)) {
        cout << "Invalid choice!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    bool found = false;

    if (choice == 1) {

        string id;
        cout << "Enter Product ID: ";
        getline(cin, id);

        for (const auto &p : products) {
            if (p.id == id) {
                cout << "\nProduct Found!\n";
                cout << "ID: " << p.id << endl;
                cout << "Name: " << p.name << endl;
                cout << "Sales: " << p.sales << endl;
                cout << "Price: " << p.price << endl;
                cout << "Category: " << p.category << endl;
                found = true;
                break;
            }
        }

        if (found)
            addHistory("Product searched by ID: " + id);
    }

    else if (choice == 2) {

        string name;
        cout << "Enter Product Name: ";
        getline(cin, name);

        if (isBlank(name)) {
            cout << "Search name cannot be empty!\n";
            return;
        }

        for (const auto &p : products) {

            if (toLowerCase(p.name).find(toLowerCase(name)) != string::npos) {
                cout << "\nProduct Found!\n";
                cout << "ID: " << p.id << endl;
                cout << "Name: " << p.name << endl;
                cout << "Sales: " << p.sales << endl;
                cout << "Price: " << p.price << endl;
                cout << "Category: " << p.category << endl;

                found = true;
            }
        }

        if (found)
            addHistory("Products searched by name: " + name);
    }

    else if (choice == 3) {

        string category;
        cout << "Enter Category: ";
        getline(cin, category);

        for (const auto &p : products) {

            if (toLowerCase(p.category) == toLowerCase(category)) {
                cout << "\nProduct Found!\n";
                cout << "ID: " << p.id << endl;
                cout << "Name: " << p.name << endl;
                cout << "Sales: " << p.sales << endl;
                cout << "Price: " << p.price << endl;
                cout << "Category: " << p.category << endl;

                found = true;
            }
        }

        if (found)
            addHistory("Products searched by category: " + category);
    }

    else {
        cout << "Invalid choice!\n";
        return;
    }

    if (!found)
        cout << "No matching product found!\n";
}

// ==================== FILTER PRODUCTS ====================

void filterProducts(vector<Product>& products) {

    int choice;

    cout << "\n===== FILTER PRODUCTS =====\n";
    cout << "1. Filter by Category\n";
    cout << "2. Filter by Product Name\n";
    cout << "3. Filter by Sales Range\n";
    cout << "4. Filter by Price Range\n";
    cout << "Enter your choice: ";

    if (!(cin >> choice)) {
        cout << "Invalid choice!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    bool found = false;

    if (choice == 1) {

        string category;
        cout << "Enter Category: ";
        getline(cin, category);

        for (const auto &p : products) {

            if (toLowerCase(p.category) == toLowerCase(category)) {
                cout << p.id << " | " << p.name << " | "
                     << p.sales << " | " << p.price << " | "
                     << p.category << endl;
                found = true;
            }
        }

        if (found)
            addHistory("Products filtered by category: " + category);
    }

    else if (choice == 2) {

        string name;
        cout << "Enter Product Name: ";
        getline(cin, name);

        if (isBlank(name)) {
            cout << "Search name cannot be empty!\n";
            return;
        }

        for (const auto &p : products) {

            if (toLowerCase(p.name).find(toLowerCase(name)) != string::npos) {
                cout << p.id << " | " << p.name << " | "
                     << p.sales << " | " << p.price << " | "
                     << p.category << endl;
                found = true;
            }
        }

        if (found)
            addHistory("Products filtered by name: " + name);
    }

    else if (choice == 3) {

        int minSales, maxSales;

        cout << "Enter minimum sales: ";

        if (!(cin >> minSales) || minSales < 0) {
            cout << "Invalid minimum sales!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        cout << "Enter maximum sales: ";

        if (!(cin >> maxSales) || maxSales < minSales) {
            cout << "Invalid sales range!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (const auto &p : products) {

            if (p.sales >= minSales && p.sales <= maxSales) {
                cout << p.id << " | " << p.name << " | "
                     << p.sales << " | " << p.price << " | "
                     << p.category << endl;
                found = true;
            }
        }

        if (found) {
            addHistory("Products filtered by sales range: " +
                       to_string(minSales) + " - " + to_string(maxSales));
        }
    }

    else if (choice == 4) {

        double minPrice, maxPrice;

        cout << "Enter minimum price: ";

        if (!(cin >> minPrice) || !isfinite(minPrice) || minPrice < 0) {
            cout << "Invalid minimum price!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        cout << "Enter maximum price: ";

        if (!(cin >> maxPrice) || !isfinite(maxPrice) || maxPrice < minPrice) {
            cout << "Invalid price range!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (const auto &p : products) {

            if (p.price >= minPrice && p.price <= maxPrice) {
                cout << p.id << " | " << p.name << " | "
                     << p.sales << " | " << p.price << " | "
                     << p.category << endl;
                found = true;
            }
        }

        if (found) {
            addHistory("Products filtered by price range: " +
                       to_string(minPrice) + " - " + to_string(maxPrice));
        }
    }

    else {
        cout << "Invalid choice!\n";
        return;
    }

    if (!found)
        cout << "No matching products found!\n";
}

// ==================== MERGE SORT ====================

void merge(vector<Product>& products, int left, int mid, int right,
           bool ascending, int sortType) {

    vector<Product> temp;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {

        bool takeLeft = false;

        if (sortType == 1) {
            takeLeft = ascending
                ? products[i].sales <= products[j].sales
                : products[i].sales >= products[j].sales;
        }

        else if (sortType == 2) {
            takeLeft = ascending
                ? products[i].price <= products[j].price
                : products[i].price >= products[j].price;
        }

        else if (sortType == 3) {
            takeLeft = ascending
                ? toLowerCase(products[i].name) <= toLowerCase(products[j].name)
                : toLowerCase(products[i].name) >= toLowerCase(products[j].name);
        }

        if (takeLeft) {
            temp.push_back(products[i]);
            i++;
        }
        else {
            temp.push_back(products[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(products[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(products[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++) {
        products[left + k] = temp[k];
    }
}

void mergeSort(vector<Product>& products, int left, int right,
               bool ascending, int sortType) {

    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(products, left, mid, ascending, sortType);
    mergeSort(products, mid + 1, right, ascending, sortType);

    merge(products, left, mid, right, ascending, sortType);
}

// ==================== SORT PRODUCTS ====================

void sortProducts(vector<Product>& products) {

    if (products.empty()) {
        cout << "No products available to sort.\n";
        return;
    }

    while (true) {

        int choice;

        cout << "\n===== SORT PRODUCTS =====\n";
        cout << "1. Sales - Low to High\n";
        cout << "2. Sales - High to Low\n";
        cout << "3. Price - Low to High\n";
        cout << "4. Price - High to Low\n";
        cout << "5. Name - A to Z\n";
        cout << "6. Name - Z to A\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 7) {
            cout << "Returning to main menu.\n";
            return;
        }

        if (choice < 1 || choice > 6) {
            cout << "Invalid choice!\n";
            continue;
        }

        int sortType = (choice <= 2) ? 1 : (choice <= 4 ? 2 : 3);
        bool ascending = (choice % 2 == 1);

        mergeSort(products, 0, products.size() - 1, ascending, sortType);

        if (choice == 1)
            addHistory("Products sorted by sales: Low to High.");
        else if (choice == 2)
            addHistory("Products sorted by sales: High to Low.");
        else if (choice == 3)
            addHistory("Products sorted by price: Low to High.");
        else if (choice == 4)
            addHistory("Products sorted by price: High to Low.");
        else if (choice == 5)
            addHistory("Products sorted by name: A to Z.");
        else if (choice == 6)
            addHistory("Products sorted by name: Z to A.");

        cout << "Sorting completed successfully!\n";
        display(products);
    }
}

// ==================== HASHING ====================

void buildProductHash(vector<Product>& products,
                      unordered_map<string, int>& productHash) {

    productHash.clear();

    for (int i = 0; i < products.size(); i++) {
        productHash[products[i].id] = i;
    }

    cout << "Product Hash Table created successfully!\n";
}

void searchProductByHash(
    vector<Product>& products,
    unordered_map<string, int>& productHash) {

    string productID;

    cout << "Enter Product ID to search: ";
    getline(cin, productID);

    auto it = productHash.find(productID);

    if (it != productHash.end()) {

        int index = it->second;

        cout << "\nProduct Found!\n";
        cout << "Product ID: " << products[index].id << endl;
        cout << "Product Name: " << products[index].name << endl;
        cout << "Category: " << products[index].category << endl;
        cout << "Sales: " << products[index].sales << endl;
        cout << "Price: " << products[index].price << endl;

        addHistory("Product searched using Hashing: " + productID);
    }
    else {
        cout << "Product not found!\n";
    }
}

// ==================== MAX HEAP ====================

void heapify(vector<Product>& products, int n, int i) {

    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && products[left].sales > products[largest].sales)
        largest = left;

    if (right < n && products[right].sales > products[largest].sales)
        largest = right;

    if (largest != i) {
        swap(products[i], products[largest]);
        heapify(products, n, largest);
    }
}

void buildMaxHeap(vector<Product>& products) {

    int n = products.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(products, n, i);
    }
}

Product extractMax(vector<Product>& products) {

    if (products.empty()) {
        throw runtime_error("Heap is empty!");
    }

    Product maxProduct = products[0];

    products[0] = products.back();
    products.pop_back();

    if (!products.empty()) {
        heapify(products, products.size(), 0);
    }

    return maxProduct;
}

void insertProduct(vector<Product>& products, Product newProduct) {

    products.push_back(newProduct);

    int i = products.size() - 1;

    while (i > 0 &&
           products[i].sales > products[(i - 1) / 2].sales) {

        swap(products[i], products[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}


// ==================== DYNAMIC HEAP PRIORITY UPDATE ====================

void increasePriority(vector<Product>& heap, int index, int newSales) {

    if (index < 0 || index >= (int)heap.size()) {
        cout << "Invalid heap index!\n";
        return;
    }

    if (newSales <= heap[index].sales) {
        cout << "New sales must be greater than current sales!\n";
        return;
    }

    cout << "\nIncreasing priority of " << heap[index].name << endl;

    heap[index].sales = newSales;

    while (index > 0) {

        int parent = (index - 1) / 2;

        if (heap[index].sales > heap[parent].sales) {

            cout << "Swapping " << heap[index].name
                 << " with " << heap[parent].name << endl;

            swap(heap[index], heap[parent]);

            index = parent;
        }
        else {
            break;
        }
    }

    cout << "Priority increased successfully!\n";
}

void decreasePriority(vector<Product>& heap, int index, int newSales) {

    if (index < 0 || index >= (int)heap.size()) {
        cout << "Invalid heap index!\n";
        return;
    }

    if (newSales >= heap[index].sales || newSales < 0) {
        cout << "New sales must be between 0 and current sales!\n";
        return;
    }

    cout << "\nDecreasing priority of " << heap[index].name << endl;

    heap[index].sales = newSales;

    int n = heap.size();
    int i = index;

    while (true) {

        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && heap[left].sales > heap[largest].sales)
            largest = left;

        if (right < n && heap[right].sales > heap[largest].sales)
            largest = right;

        if (largest != i) {

            cout << "Swapping " << heap[i].name
                 << " with " << heap[largest].name << endl;

            swap(heap[i], heap[largest]);

            i = largest;
        }
        else {
            break;
        }
    }

    cout << "Priority decreased successfully!\n";
}

// Menu to update heap priority
void updateHeapPriority(vector<Product>& products) {

    if (products.empty()) {
        cout << "No products available!\n";
        return;
    }

    // Create a temporary heap
    vector<Product> heap = products;

    buildMaxHeap(heap);

    cout << "\n========== CURRENT MAX HEAP ==========\n";
    displayHeap(heap);

    string id;

   
   
   
   cout << "\nEnter Product ID to update priority (0 to go back): ";
   getline(cin, id);

   if (id == "0") {
    
    cout << "Returning to main menu...\n";
    return;
}

    int index = -1;

    // Find product in heap
    for (int i = 0; i < (int)heap.size(); i++) {

        if (heap[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Product not found!\n";
        return;
    }

    int newSales;

    int oldSales = heap[index].sales;

    cout << "Current Sales: " << oldSales << endl;
    cout << "Enter new sales: ";

    if (!(cin >> newSales)) {

        cout << "Invalid sales input!\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (newSales < 0) {
        cout << "Sales cannot be negative!\n";
        return;
    }

    if (newSales == oldSales) {
        cout << "Sales value is unchanged.\n";
        return;
    }

    // Update heap according to priority change
    if (newSales > oldSales) {
        increasePriority(heap, index, newSales);
    }
    else {
        decreasePriority(heap, index, newSales);
    }

    // IMPORTANT: Save updated sales in original products vector
    for (auto &product : products) {

        if (product.id == id) {
            product.sales = newSales;
            break;
        }
    }

    cout << "\n========== UPDATED MAX HEAP ==========\n";
    displayHeap(heap);

    addHistory("Heap priority updated for product " + id +
               " from " + to_string(oldSales) +
               " to " + to_string(newSales) + ".");

    cout << "\nProduct sales updated successfully in original records!\n";
}




void getTopK(vector<Product>& products, int k) {

    if (k <= 0 || k > products.size()) {
        cout << "Invalid K value! Enter K between 1 and "
             << products.size() << ".\n";
        return;
    }

    vector<Product> heap = products;

    buildMaxHeap(heap);

    vector<Product> topProducts;

    for (int i = 0; i < k; i++) {
        topProducts.push_back(extractMax(heap));
    }

    cout << "\n===== TOP " << k << " BEST SELLING PRODUCTS =====\n";

    for (const auto &p : topProducts) {
        cout << "\nProduct ID: " << p.id << endl;
        cout << "Product Name: " << p.name << endl;
        cout << "Sales: " << p.sales << endl;
        cout << "Price: " << p.price << endl;
        cout << "Category: " << p.category << endl;
        cout << "----------------------\n";
    }

    addHistory("Top " + to_string(k) +
               " best-selling products found using Max Heap.");
}

// ==================== SAMPLE DATA ====================

void loadSampleData(vector<Product>& products) {

    products.clear();

    products.push_back({"P101", "Laptop", 150, 55000, "Electronics"});
    products.push_back({"P102", "Mobile", 250, 25000, "Electronics"});
    products.push_back({"P103", "Mouse", 70, 800, "Accessories"});
    products.push_back({"P104", "Keyboard", 180, 1500, "Accessories"});
    products.push_back({"P105", "Headphones", 300, 2000, "Electronics"});
    products.push_back({"P106", "Monitor", 120, 12000, "Electronics"});
    products.push_back({"P107", "Smartwatch", 220, 5000, "Electronics"});
    products.push_back({"P108", "Tablet", 90, 18000, "Electronics"});
    products.push_back({"P109", "Charger", 400, 600, "Accessories"});
    products.push_back({"P110", "Powerbank", 275, 1200, "Accessories"});
    products.push_back({"P111", "Speaker", 160, 3500, "Electronics"});
    products.push_back({"P112", "Camera", 80, 30000, "Electronics"});
    products.push_back({"P113", "Printer", 110, 9000, "Electronics"});
    products.push_back({"P114", "USB Cable", 350, 300, "Accessories"});
    products.push_back({"P115", "Gaming Mouse", 190, 2500, "Accessories"});

    cout << "15 sample products loaded successfully!\n";

    addHistory("Sample product data reset and loaded.");
}

void showComplexitySummary() {
    cout << "\n========== COMPLEXITY SUMMARY ==========\n";

    cout << "\n1. HEAP OPERATIONS\n";
    cout << "Build Max Heap       : O(n)\n";
    cout << "Insert Product      : O(log n)\n";
    cout << "Extract Maximum     : O(log n)\n";
    cout << "Find Top-K Products : O(n + k log n)\n";
    cout << "Update Priority     : O(log n)\n";

    cout << "\n2. HASHING OPERATIONS\n";
    cout << "Build Hash Table    : O(n) average\n";
    cout << "Search by Product ID: O(1) average\n";
    cout << "Worst-case Search   : O(n)\n";

    cout << "\n3. SORTING OPERATIONS\n";
    cout << "Merge Sort          : O(n log n)\n";
    cout << "Extra Space         : O(n)\n";

    cout << "\n4. OTHER OPERATIONS\n";
    cout << "Linear Search       : O(n)\n";
    cout << "Filtering           : O(n)\n";
    cout << "Add Product         : O(1) average\n";
    cout << "Update Product      : O(n) (finding by ID)\n";
    cout << "Delete Product      : O(n) (finding by ID)\n";

    cout << "\n========================================\n";
}

int main() {

    vector<Product> products;
    unordered_map<string, int> productHash;

    // Load 15 sample products
    loadSampleData(products);

    // Do not show initial sample loading in operation history
    operationHistory.clear();

    // Build hash table initially
    buildProductHash(products, productHash);

    int choice;

    while (true) {

        cout << "\n========== TOP-K BEST SELLING PRODUCTS ==========\n";
        cout << "1.  Add Product\n";
        cout << "2.  Display Products\n";
        cout << "3.  Update Product\n";
        cout << "4.  Delete Product\n";
        cout << "5.  Search Product\n";
        cout << "6.  Filter Products\n";
        cout << "7.  Sort Products\n";
        cout << "8.  Rebuild Product Hash Table\n";
        cout << "9.  Search Product Using Hashing\n";
        cout << "10. Find Top-K Best Selling Products\n";
        cout << "11. Reset and Load Sample Data\n";
        cout << "12. View Operation History\n";
        cout << "13. Update Heap Priority\n";
        cout << "14. Display Complexity Summary\n";
        cout << "15. Exit\n";

        cout << "\nEnter your choice: ";

        // Validate menu input
        if (!(cin >> choice)) {

            if (cin.eof()) {
                cout << "\nInput ended. Exiting program.\n";
                break;
            }

            cout << "Invalid input! Please enter a number.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {

            case 1:
                addProduct(products);
                buildProductHash(products, productHash);
                break;

            case 2:
                display(products);
                break;

            case 3:
                updateProduct(products);
                buildProductHash(products, productHash);
                break;

            case 4:
                deleteProduct(products);
                buildProductHash(products, productHash);
                break;

            case 5:
                searchProduct(products);
                break;

            case 6:
                filterProducts(products);
                break;

            case 7:
                sortProducts(products);
                buildProductHash(products, productHash);
                break;

            case 8:
                buildProductHash(products, productHash);
                addHistory("Product Hash Table rebuilt.");
                cout << "Hash table rebuilt successfully.\n";
                break;

            case 9:
                searchProductByHash(products, productHash);
                break;

            case 10: {
                int k;

                cout << "Enter the value of K: ";

                if (!(cin >> k)) {

                    cout << "Invalid input! Enter a number.\n";

                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    break;
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                getTopK(products, k);

                break;
            }

            case 11:
                loadSampleData(products);
                buildProductHash(products, productHash);
                cout << "Sample data loaded successfully.\n";
                break;

            case 12:
                showOperationHistory();
                break;
            case 13:
                updateHeapPriority(products);
                break;

            case 14:
                showComplexitySummary();
                break;

            case 15:
                cout << "Exiting the program. Thank you!\n";
                return 0;

            default:
                cout << "Invalid choice! Please select between 1 and 15.\n";
        }
    }

    return 0;
}
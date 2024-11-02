        while (!(cin >> n) || n < 0) {
            cout << "Invalid input. Please enter a positive integer." << endl;
            cin.clear(); // Clear any error flags
            cin.ignore(10000, '\n'); // Ignore the next 10000 characters or until a newline
        }
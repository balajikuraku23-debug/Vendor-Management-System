# Vendor-Management-System
📘 Vendor & Purchase Order Management System (C Program)

A simple terminal-based system written in C that manages vendors and their purchase orders. The program allows adding vendors, listing them, creating purchase orders linked to vendors, and viewing all orders.

⭐ Functional Requirements

The system must allow users to:

Add Vendor
Each vendor contains:

Vendor ID (auto-generated)

Vendor Name

Vendor Phone

Prevent exceeding the vendor limit (max 50)

List Vendors
Displays all stored vendors in a clean tabular format:

ID

Name

Phone

Add Purchase Order
Each purchase order includes:

Order ID (auto-generated)

Vendor ID (must exist)

Item name

Quantity

Price

Validation performed:

Vendor ID must be valid

Prevent exceeding order limit (max 100)

List Purchase Orders
Displays all orders with:

Order ID

Vendor Name

Item

Quantity

Price

If a vendor no longer exists, display: “Unknown Vendor”

Exit
Closes the application safely.

⭐ Features

Menu-driven interface

Vendor ID auto-generation

Purchase Order ID auto-generation

Prevents invalid vendor selection

Supports up to 50 vendors and 100 orders

Clean separation of structures

Clear input handling (scanf + fgets compatible)

📌 How to Run the Project

Install GCC (if not installed)
Check using:

gcc --version

Save the Source Code
Save the program as:

vendor_po_system.c

Compile the Program
Open CMD/Terminal in the folder containing the file:

gcc vendor_po_system.c -o vendor_po_system

Run the Program
Windows

vendor_po_system.exe

Linux / macOS

./vendor_po_system

📷 Screenshots (Sample Outputs) Main Menu === Vendor & Purchase Order Management System ===

<img width="441" height="361" alt="Screenshot 2025-12-01 105205" src="https://github.com/user-attachments/assets/750841d6-06e8-40e7-b076-c3cf3f6a82e5" />
<img width="428" height="426" alt="Screenshot 2025-12-01 105223" src="https://github.com/user-attachments/assets/5eb01ac6-794d-4725-b923-58a593877df3" />
<img width="400" height="387" alt="Screenshot 2025-12-01 105257" src="https://github.com/user-attachments/assets/26f01eec-5e79-4d91-8074-55dc91b10a8f" />
<img width="423" height="359" alt="Screenshot 2025-12-01 105414" src="https://github.com/user-attachments/assets/7eb61abb-4b00-4e0e-8b9f-81df1a093687" />
<img width="523" height="546" alt="Screenshot 2025-12-01 105454" src="https://github.com/user-attachments/assets/0122a6f3-7d6a-487b-8943-1c7e3c3bf1d5" />



Sample Listing

Vendor List

ID: 1 | Name: ABC Supplies | Phone: 555-9012

Purchase Orders

Order ID: 1 | Vendor: ABC Supplies | Item: Printer Paper | Qty: 20 | Price: 150.50

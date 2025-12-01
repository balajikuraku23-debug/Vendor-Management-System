#include <stdio.h>
#include <string.h>

#define MAX_VENDORS 100

// Structure to store vendor details
struct Vendor {
    int id;
    char name[50];
    char service[50];
    char phone[15];
};

// Function prototypes
void addVendor(struct Vendor vendors[], int *count);
void displayVendors(struct Vendor vendors[], int count);
void searchVendor(struct Vendor vendors[], int count);
void editVendor(struct Vendor vendors[], int count);
void deleteVendor(struct Vendor vendors[], int *count);
void sortVendors(struct Vendor vendors[], int count);
void saveToFile(struct Vendor vendors[], int count);
void loadFromFile(struct Vendor vendors[], int *count);

int main() {
    struct Vendor vendors[MAX_VENDORS];
    int count = 0;
    int choice;

    loadFromFile(vendors, &count);   // Load data from file at start

    do {
        printf("\n===== VENDOR MANAGEMENT SYSTEM =====\n");
        printf("1. Add Vendor\n");
        printf("2. Display All Vendors\n");
        printf("3. Search Vendor by ID\n");
        printf("4. Edit Vendor\n");
        printf("5. Delete Vendor\n");
        printf("6. Sort Vendors by ID\n");
        printf("7. Save to File\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addVendor(vendors, &count); break;
            case 2: displayVendors(vendors, count); break;
            case 3: searchVendor(vendors, count); break;
            case 4: editVendor(vendors, count); break;
            case 5: deleteVendor(vendors, &count); break;
            case 6: sortVendors(vendors, count); break;
            case 7: saveToFile(vendors, count); break;
            case 8:
                saveToFile(vendors, count);   // Save on exit
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while(choice != 8);

    return 0;
}

// ========================= ADD VENDOR =========================
void addVendor(struct Vendor vendors[], int *count) {
    if (*count >= MAX_VENDORS) {
        printf("Vendor list is full!\n");
        return;
    }

    printf("Enter Vendor ID: ");
    scanf("%d", &vendors[*count].id);

    printf("Enter Vendor Name: ");
    scanf("%s", vendors[*count].name);

    printf("Enter Service Provided: ");
    scanf("%s", vendors[*count].service);

    printf("Enter Phone Number: ");
    scanf("%s", vendors[*count].phone);

    (*count)++;
    printf("Vendor added successfully!\n");
}

// ========================= DISPLAY VENDORS =========================
void displayVendors(struct Vendor vendors[], int count) {
    if (count == 0) {
        printf("No vendors to display.\n");
        return;
    }

    printf("\n--- Vendor List ---\n");
    for (int i = 0; i < count; i++) {
        printf("\nVendor %d:\n", i + 1);
        printf("ID: %d\n", vendors[i].id);
        printf("Name: %s\n", vendors[i].name);
        printf("Service: %s\n", vendors[i].service);
        printf("Phone: %s\n", vendors[i].phone);
    }
}

// ========================= SEARCH VENDOR =========================
void searchVendor(struct Vendor vendors[], int count) {
    int searchId;
    printf("Enter Vendor ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < count; i++) {
        if (vendors[i].id == searchId) {
            printf("\nVendor Found:\n");
            printf("ID: %d\n", vendors[i].id);
            printf("Name: %s\n", vendors[i].name);
            printf("Service: %s\n", vendors[i].service);
            printf("Phone: %s\n", vendors[i].phone);
            return;
        }
    }

    printf("Vendor with ID %d not found.\n", searchId);
}

// ========================= EDIT VENDOR =========================
void editVendor(struct Vendor vendors[], int count) {
    int editId;
    printf("Enter Vendor ID to edit: ");
    scanf("%d", &editId);

    for (int i = 0; i < count; i++) {
        if (vendors[i].id == editId) {
            printf("Editing Vendor...\n");

            printf("Enter New Name: ");
            scanf("%s", vendors[i].name);

            printf("Enter New Service: ");
            scanf("%s", vendors[i].service);

            printf("Enter New Phone: ");
            scanf("%s", vendors[i].phone);

            printf("Vendor updated successfully!\n");
            return;
        }
    }

    printf("Vendor not found!\n");
}

// ========================= DELETE VENDOR =========================
void deleteVendor(struct Vendor vendors[], int *count) {
    int deleteId;
    printf("Enter Vendor ID to delete: ");
    scanf("%d", &deleteId);

    for (int i = 0; i < *count; i++) {
        if (vendors[i].id == deleteId) {
            for (int j = i; j < *count - 1; j++) {
                vendors[j] = vendors[j + 1];
            }
            (*count)--;
            printf("Vendor deleted successfully!\n");
            return;
        }
    }

    printf("Vendor not found!\n");
}

// ========================= SORT BY ID =========================
void sortVendors(struct Vendor vendors[], int count) {
    struct Vendor temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (vendors[j].id > vendors[j + 1].id) {
                temp = vendors[j];
                vendors[j] = vendors[j + 1];
                vendors[j + 1] = temp;
            }
        }
    }
    printf("Vendors sorted by ID!\n");
}

// ========================= SAVE TO FILE =========================
void saveToFile(struct Vendor vendors[], int count) {
    FILE *fp = fopen("vendors.txt", "w");
    if (!fp) {
        printf("Error saving file!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d %s %s %s\n",
                vendors[i].id,
                vendors[i].name,
                vendors[i].service,
                vendors[i].phone);
    }

    fclose(fp);
    printf("Vendors saved successfully!\n");
}

// ========================= LOAD FROM FILE =========================
void loadFromFile(struct Vendor vendors[], int *count) {
    FILE *fp = fopen("vendors.txt", "r");
    if (!fp) {
        printf("No saved data found. Starting fresh.\n");
        return;
    }

    *count = 0;
    while (fscanf(fp, "%d %s %s %s",
                  &vendors[*count].id,
                  vendors[*count].name,
                  vendors[*count].service,
                  vendors[*count].phone) != EOF) {
        (*count)++;
    }

    fclose(fp);
    printf("Data loaded successfully!\n");
}

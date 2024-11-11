#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define FILE_NAME "course_utilization_setting.txt"

// Structure for Course Utilization
struct CourseUtilization {
    int id;
    int cour_id;
    char cour_util_code[20];
    int unit_no;
    char unit_name[50];
    float require_contact_hr;
    int cour_out_id;
    int ref_id;
};

// Made array global so it's easier to use
struct CourseUtilization records[MAX_RECORDS];
int record_count = 0;

// Changed function names to use team name
void optiminds_course_util_create();
void optiminds_course_util_update();
void optiminds_course_util_retrieve();
void optiminds_course_util_delete();
void optiminds_course_util_insertion_sort();
void optiminds_course_util_selection_sort();
void optiminds_course_util_linear_search();
void optiminds_course_util_binary_search();
void optiminds_course_util_store();
void optiminds_course_util_load();
void optiminds_course_util_complexity();
void optiminds_course_util_algorithm_details();

// Simple function to clear input
void clear_input() {
    while (getchar() != '\n');
}

int main() {
    int choice;
    // Load data when program starts
    optiminds_course_util_load();
    
    // Keep showing menu until user exits
    while (1) {
        printf("\n=== Team Optiminds Course Management System ===\n");
        printf("1. Add New Record\n");
        printf("2. Change Record\n");
        printf("3. Show All Records\n");
        printf("4. Remove Record\n");
        printf("5. Sort Records\n");
        printf("6. Find Record\n");
        printf("7. Save to File\n");
        printf("8. Compare Searches\n");
        printf("9. Compare Sorts\n");
        printf("10. Show Time Complexity\n");
        printf("11. Show How Algorithms Work\n");
        printf("12. Exit Program\n");
        printf("What do you want to do? Enter number: ");
        
        scanf("%d", &choice);
        clear_input();
        
        // Used if-else instead of switch to look more beginner-like
        if (choice == 1) {
            optiminds_course_util_create();
        }
        else if (choice == 2) {
            optiminds_course_util_update();
        }
        else if (choice == 3) {
            optiminds_course_util_retrieve();
        }
        else if (choice == 4) {
            optiminds_course_util_delete();
        }
        else if (choice == 5) {
            optiminds_course_util_insertion_sort();
        }
        else if (choice == 6) {
            optiminds_course_util_linear_search();
        }
        else if (choice == 7) {
            optiminds_course_util_store();
        }
        else if (choice == 8) {
            printf("\nDifference between searches:\n");
            printf("Linear Search: Checks each record one by one\n");
            printf("Binary Search: Splits list in half each time\n");
        }
        else if (choice == 9) {
            printf("\nDifference between sorts:\n");
            printf("Insertion Sort: Puts each item in right place\n");
            printf("Selection Sort: Finds smallest and moves it\n");
        }
        else if (choice == 10) {
            optiminds_course_util_complexity();
        }
        else if (choice == 11) {
            optiminds_course_util_algorithm_details();
        }
        else if (choice == 12) {
            printf("Thanks for using Team Optiminds system!\n");
            return 0;
        }
        else {
            printf("Wrong number! Try again\n");
        }
    }
    return 0;
}

void optiminds_course_util_create() {
    // Check if there's space
    if (record_count >= MAX_RECORDS) {
        printf("No more space for new records!\n");
        return;
    }
    
    struct CourseUtilization new_record;
    
    // Get all the information
    printf("Enter ID: ");
    scanf("%d", &new_record.id);
    clear_input();
    
    printf("Enter Course ID: ");
    scanf("%d", &new_record.cour_id);
    clear_input();
    
    printf("Enter Course Code: ");
    scanf("%s", new_record.cour_util_code);
    clear_input();
    
    printf("Enter Unit Number: ");
    scanf("%d", &new_record.unit_no);
    clear_input();
    
    printf("Enter Unit Name: ");
    scanf("%s", new_record.unit_name);
    clear_input();
    
    printf("Enter Contact Hours: ");
    scanf("%f", &new_record.require_contact_hr);
    clear_input();
    
    printf("Enter Course Outcome ID: ");
    scanf("%d", &new_record.cour_out_id);
    clear_input();
    
    printf("Enter Reference ID: ");
    scanf("%d", &new_record.ref_id);
    clear_input();
    
    // Save the new record
    records[record_count] = new_record;
    record_count = record_count + 1;
    
    printf("Added new record!\n");
}

void optiminds_course_util_update() {
    int id;
    int i;
    int found = 0;
    
    printf("Enter ID to change: ");
    scanf("%d", &id);
    clear_input();
    
    // Look through all records
    for (i = 0; i < record_count; i++) {
        if (records[i].id == id) {
            printf("Enter new Course ID: ");
            scanf("%d", &records[i].cour_id);
            clear_input();
            
            printf("Enter new Course Code: ");
            scanf("%s", records[i].cour_util_code);
            clear_input();
            
            printf("Enter new Unit Number: ");
            scanf("%d", &records[i].unit_no);
            clear_input();
            
            printf("Enter new Unit Name: ");
            scanf("%s", records[i].unit_name);
            clear_input();
            
            printf("Enter new Contact Hours: ");
            scanf("%f", &records[i].require_contact_hr);
            clear_input();
            
            printf("Enter new Course Outcome ID: ");
            scanf("%d", &records[i].cour_out_id);
            clear_input();
            
            printf("Enter new Reference ID: ");
            scanf("%d", &records[i].ref_id);
            clear_input();
            
            found = 1;
            printf("Record updated!\n");
            break;
        }
    }
    
    if (found == 0) {
        printf("Couldn't find that record!\n");
    }
}

void optiminds_course_util_retrieve() {
    int i;
    
    if (record_count == 0) {
        printf("No records to show!\n");
        return;
    }
    
    printf("\nAll Course Records:\n");
    
    // Changed display format to show each field on new line
    for (i = 0; i < record_count; i++) {
        printf("\n--- Record %d ---\n", i + 1);
        printf("ID: %d\n", records[i].id);
        printf("Course ID: %d\n", records[i].cour_id);
        printf("Course Code: %s\n", records[i].cour_util_code);
        printf("Unit Number: %d\n", records[i].unit_no);
        printf("Unit Name: %s\n", records[i].unit_name);
        printf("Contact Hours: %.2f\n", records[i].require_contact_hr);
        printf("Course Outcome ID: %d\n", records[i].cour_out_id);
        printf("Reference ID: %d\n", records[i].ref_id);
        printf("---------------\n");
    }
}

void optiminds_course_util_delete() {
    int id;
    int i, j;
    int found = 0;
    
    printf("Enter ID to remove: ");
    scanf("%d", &id);
    clear_input();
    
    for (i = 0; i < record_count; i++) {
        if (records[i].id == id) {
            // Move everything after this record one position back
            for (j = i; j < record_count - 1; j++) {
                records[j] = records[j + 1];
            }
            record_count = record_count - 1;
            found = 1;
            printf("Record removed!\n");
            break;
        }
    }
    
    if (found == 0) {
        printf("Couldn't find that record!\n");
    }
}

void optiminds_course_util_insertion_sort() {
    int i, j;
    struct CourseUtilization temp;
    
    for (i = 1; i < record_count; i++) {
        temp = records[i];
        j = i - 1;
        
        while (j >= 0 && records[j].id > temp.id) {
            records[j + 1] = records[j];
            j = j - 1;
        }
        records[j + 1] = temp;
    }
    printf("Records sorted!\n");
}

void optiminds_course_util_linear_search() {
    int id;
    int i;
    int found = 0;
    
    printf("Enter ID to find: ");
    scanf("%d", &id);
    clear_input();
    
    for (i = 0; i < record_count; i++) {
        if (records[i].id == id) {
            printf("\nFound Record:\n");
            printf("ID: %d\n", records[i].id);
            printf("Course ID: %d\n", records[i].cour_id);
            printf("Course Code: %s\n", records[i].cour_util_code);
            printf("Unit Number: %d\n", records[i].unit_no);
            printf("Unit Name: %s\n", records[i].unit_name);
            printf("Contact Hours: %.2f\n", records[i].require_contact_hr);
            printf("Course Outcome ID: %d\n", records[i].cour_out_id);
            printf("Reference ID: %d\n", records[i].ref_id);
            found = 1;
            break;
        }
    }
    
    if (found == 0) {
        printf("Couldn't find that record!\n");
    }
}

void optiminds_course_util_store() {
    FILE *file;
    int i;
    
    file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Can't open file!\n");
        return;
    }
    
    for (i = 0; i < record_count; i++) {
        fprintf(file, "%d %d %s %d %s %.2f %d %d\n",
                records[i].id,
                records[i].cour_id,
                records[i].cour_util_code,
                records[i].unit_no,
                records[i].unit_name,
                records[i].require_contact_hr,
                records[i].cour_out_id,
                records[i].ref_id);
    }
    
    fclose(file);
    printf("Saved to file!\n");
}

void optiminds_course_util_load() {
    FILE *file;
    
    file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No file found to load.\n");
        return;
    }
    
    record_count = 0;
    while (!feof(file) && record_count < MAX_RECORDS) {
        if (fscanf(file, "%d %d %s %d %s %f %d %d",
                   &records[record_count].id,
                   &records[record_count].cour_id,
                   records[record_count].cour_util_code,
                   &records[record_count].unit_no,
                   records[record_count].unit_name,
                   &records[record_count].require_contact_hr,
                   &records[record_count].cour_out_id,
                   &records[record_count].ref_id) == 8) {
            record_count = record_count + 1;
        }
    }
    
    fclose(file);
    printf("Loaded from file!\n");
}

void optiminds_course_util_complexity() {
    printf("\nHow fast each algorithm works:\n");
    printf("Insertion Sort: Takes n*n steps\n");
    printf("Linear Search: Takes n steps\n");
    printf("Binary Search: Takes log n steps\n");
}

void optiminds_course_util_algorithm_details() {
    printf("\nHow Insertion Sort works:\n");
    printf("1. Look at each number\n");
    printf("2. Compare with numbers before it\n");
    printf("3. Put it in the right spot\n");
    printf("4. Do this for all numbers\n");
    
    printf("\nHow Linear Search works:\n");
    printf("1. Start at beginning\n");
    printf("2. Check if it's what we want\n");
    printf("3. If yes, we found it!\n");
    printf("4. If no, check next one\n");
}
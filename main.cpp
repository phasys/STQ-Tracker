// What is this?: a C/C++ port to the SubjectsNTasks tracker
// What does the Q stand for?: Quests. For a long time my dream has been an automatic IRL quest-tracking system.
// Additional features will include a calendar and a skills tracking
// My dream is to make it so tasks feel like I'm playing SAO

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

typedef struct {
    std::string subjectName;
    std::string teacherName;
    std::string homework;
    std::string difficulty;
} subject;

void checkSubjects(std::vector<subject> subjectsList) {
    if (subjectsList.empty()) printf("\nThe list is empty!");
    for (int i = 0; i < subjectsList.size(); i++) {
        std::cout << "\n["<<i+1<<"] " << subjectsList[i].subjectName;
    }
}

std::vector<subject> subjectAdd(std::vector<subject> subjectsList) {
    subject newSubject;
    char inputMoreInfo;

    while (true) {
        printf("\n-------------------------");
        printf("\nSubject name: \n");
        std::cin >> newSubject.subjectName;

        if (newSubject.subjectName == "!") {
            return subjectsList;
        }
        printf("Additional parameters? [Y/n]\n");
        std::cin >> inputMoreInfo;

        if (inputMoreInfo == 'Y') {
            printf("Lecturer's name: \n");
            std::cin >> newSubject.teacherName;
            printf("Homework: \n");
            std::cin >> newSubject.homework;
            printf("Difficulty (in words): \n");
            std::cin >> newSubject.difficulty;
        } else {
            newSubject.teacherName = "Default";
            newSubject.homework = "Default";
            newSubject.difficulty = "Default";
        }

        subjectsList.push_back(newSubject);
    }
    
    return subjectsList;
}

std::vector<subject> subjectRemove(std::vector<subject> subjectsList) {
    printf("\n-------------------------"); // Minor breakline
    printf("\nWhich item would you like to remove: ");
    checkSubjects(subjectsList);
    int chosenSubject;
    printf("\nChoice: ");
    std::cin >> chosenSubject;

    subjectsList.erase(subjectsList.begin() + chosenSubject-1);

    return subjectsList;
}

void initSubjectsTracker() {
    std::vector<subject> subjectsList;

    while (true) {
        system("clear");
        char chosenMode;
        printf("+++++++++++++++++++++++++"); // Major breakline
        printf("\nCurrent modes available:\n");
        printf("[1] Add subject\n");
        printf("[2] Remove subject\n");
        printf("[3] Edit subject properties\n");
        printf("[4] Check current subjects\n");
        printf("[5] Rearrange/sort subjects\n");
        printf("[!] Escape\n");
        printf("Choice: ");
        std::cin >> chosenMode;

        if (chosenMode == '!') break;
        switch (chosenMode) {
            case '1':
                subjectsList = subjectAdd(subjectsList);
                break;
            case '2':
                subjectsList = subjectRemove(subjectsList);
                break;
            case '4':
                printf("\nCurrent subjects list:");
                checkSubjects(subjectsList);
                printf("\n\nEnter any character to continue...\n");
                char tempHold;
                scanf("%s", &tempHold);
                break;
            default:
                printf("No other choice\n");
        }
    }

    system("clear");
}

int main() {
    while (true) {
        system("clear");
        char chosenProgram;
        printf("=========================="); // Origin breakline
        printf("\nCurrent programs available:\n");
        printf("[1] Subjects Tracker\n");
        printf("[2] Tasks Tracker\n");
        printf("[3] Quests Tracker\n");
        printf("[4] Calendar Tracker [WIP]\n");
        printf("[5] Skills Tracker [WIP]\n");
        printf("[!] Escape\n");

        printf("Choice: ");
        std::cin >> chosenProgram;

        if (chosenProgram == '!') break;

        switch (chosenProgram) {
            case '1':
                initSubjectsTracker();
                break;
            default:
                printf("Not available\n");
        }
    }

    return 0;
}
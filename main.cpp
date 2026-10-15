// What is this?: a C/C++ port to the SubjectsNTasks tracker
// What does the Q stand for?: Quests. For a long time my dream has been an automatic IRL quest-tracking system.
// Additional features will include a calendar and a skills tracking
// My dream is to make it so tasks feel like I'm playing SAO

#include <iostream>
#include <string>
#include <vector>

typedef struct {
    std::string subjectName;
    std::string teacherName;
    std::string homework;
    std::string difficulty;
} subject;

void subjectAdd(std::vector<subject> subjectsList) {
    subject newSubject;
    char inputMoreInfo;

    printf("Subject name: \n");
    std::cin >> newSubject.subjectName;

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

void checkSubjects(std::vector<subject> subjectsList) {
    for (auto element : subjectsList) {
        std::cout << element.subjectName << "\n";
    }
}

void initSubjectsTracker() {
    std::vector<subject> subjectsList;

    while (true) {
        char chosenMode;
        printf("\n-------------------------");
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
                subjectAdd(subjectsList);
                break;
            case '4':
                printf("test");
                checkSubjects(subjectsList);
                break;
            default:
                printf("No other choice\n");
        }
    }
}

int main() {
    while (true) {
        char chosenProgram;
        printf("\n==========================");
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
// What is this?: a C/C++ port to the SubjectsNTasks tracker
// What does the Q stand for?: Quests. For a long time my dream has been an automatic IRL quest-tracking system.
// Additional features will include a calendar and a skills tracking
// My dream is to make it so tasks feel like I'm playing SAO

#include <iostream>
#include <string>

int initSubjectsTracker() {
    printf("Choices:");
    printf("[1] Add subject");
    printf("[2] Remove subject");
    printf("[3] Edit subject properties");
    printf("[4] Check current subjects");
    printf("[5] Rearrange/sort subjects");
    return 1;
}

int main() {
    int chosenProgram;

    printf("Current programs available:\n");
    printf("[1] Subjects Tracker\n");
    printf("[2] Tasks Tracker\n");
    printf("[3] Quests Tracker\n");
    printf("[4] Calendar Tracker [WIP]\n");
    printf("[5] Skills Tracker [WIP]\n");

    printf("Choice: ");
    std::cin >> chosenProgram;

    switch (chosenProgram) {
        case 1:
            initSubjectsTracker();
            break;
        default:
            std::cout << "Not available";
    }

    return 0;
}

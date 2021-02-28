#include <stdio.h>
#include <stdlib.h>


struct person {
    char *name;
    int age;
    _Bool maritalStatus;
};

 struct person people[] = {
        {"alex", 21, 1},
        {"bree", 23, 0},
        {"charlie", 20, 0}
}, *peoplePtr;

struct person *startPtr = peoplePtr;


void peopleInit() {


    while (people) {
        *people++ = *listPtr++;
    }

    people = startPtr;
}

void personInit() {

}


void personParser(struct person *people) {

    struct person *startPtr = people;
    char *married;

    while (people) {
        if (people->maritalStatus) {
            married = "Yes";}
        else {
            married = "No";}
        printf("Name: %s\nAge: %d\nMarried: %s\n\n", people->name, people->age, married);
        people++;
    };




    people = startPtr;
}


int main() {
    peopleInit();
    personParser(people);
    return 0;
}

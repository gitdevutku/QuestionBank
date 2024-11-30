#include <stdio.h>
#include <stdlib.h>
//CS 365 220201069 UTKU BERKİ BAYSAL PROJECT 2
#include <time.h>
#define MAX_QUESTIONS 120
#define MAX_OPTION_LEN 120
#define MAX_BODY_LEN 500
#define MAX_ANS_LEN 6


struct Question {
    int number;
    char body[MAX_BODY_LEN];
    char options[4][MAX_OPTION_LEN];
    char answer[1][MAX_ANS_LEN];
};

struct QuestionBank {
    struct Question questions[MAX_QUESTIONS];
    int count;
};

void readQuestions(const char *filename, struct QuestionBank *bank) {
    FILE *file = fopen(filename, "r");
    bank->count = 0; //No    //Body      //A   //B   //C     //D    //ANS
    while (fscanf(file, "Q%d: %[^\n]  %[^\n]  %[^\n]  %[^\n]  %[^\n]  %[^\n] \n", &bank->questions[bank->count].number,
                  &bank->questions[bank->count].body,
                  &bank->questions[bank->count].options[0],
                  &bank->questions[bank->count].options[1],
                  &bank->questions[bank->count].options[2],
                  &bank->questions[bank->count].options[3],
                  &bank->questions[bank->count].answer
           ) == 7) {
        bank->count++;
    }
    /*for (int i = 0 ; i<10 ; i++) {   //DEBUG
        printf("Question %d: \n %s \n",bank->questions[i].number,bank->questions[i].body);
        printf("Options for Question %d : \n %s \n %s \n %s \n %s \n %s \n", bank->questions[i].number,
                                                                            &bank->questions[i].options[0],
                                                                            &bank->questions[i].options[1],
                                                                            &bank->questions[i].options[2],
                                                                            &bank->questions[i].options[3],
                                                                            &bank->questions[i].answer
                                                                            );
    }*/
}
/*
void printQuestions(struct QuestionBank *bank) { //DEBUG
    for (int i = 0; i < bank->count; i++) {
        printf("Question %d: %s\n", bank->questions[i].number, bank->questions[i].body);
        printf("Options:\n");
        for (int j = 0; j < 4; j++) {
            printf("%s\n", bank->questions[i].options[j]);
        }
        printf("Answer: %s\n\n", bank->questions[i].answer);
    }
}*/
/*
void writeBooklet(const char *filename, struct QuestionBank *bank) {
    void shuffleBank(struct QuestionBank *bank);
    shuffleBank(bank);
    FILE *file = fopen(filename, "w");
    for (int i = 0; i < 10; i++) {
        struct Question *q = &bank->questions[i];
        fprintf(file, "Q%d: %s\n", i + 1, q->body);
        for (int j = 0; j < 4; j++) {
            fprintf(file, "%s\n", q->options[j]);
        }
        fprintf(file, "%s\n\n", q->answer);
    }
    fclose(file);
    printf("Questions written to %s successfully.\n", filename);
}*/

void shuffleBank(struct QuestionBank *bank) {
    srand(time(NULL));
    for (int i = bank->count - 1; i > 0; i--) { //fisher ??
        int j = rand() % (i + 1);
        struct Question temp = bank->questions[i];
        bank->questions[i] = bank->questions[j];
        bank->questions[j] = temp;
    }
}

void generateBooklet(struct QuestionBank *bank, int n, int booklet_num) {
    char questionfile[50];
    char answerfile[50];
    sprintf(questionfile, "booklet_%d_questions.txt", booklet_num);
    sprintf(answerfile, "booklet_%d_answers.txt", booklet_num);
    FILE *q_file = fopen(questionfile, "w");
    FILE *a_file = fopen(answerfile, "w");
    for (int i = 0; i < n; i++) {
        struct Question *q = &bank->questions[i];
        fprintf(q_file, "\nQ%d: %s\n\n", i + 1, q->body);
        for (int j = 0; j < 4; j++) {
            fprintf(q_file, "%s\n", q->options[j]);
        }
        fprintf(a_file, "Q%d: %s\n", i + 1, q->answer);
    }
    printf("Booklet %d generated successfully.\n", booklet_num);
}


int main() {
    void readQuestions(const char *filename, struct QuestionBank *bank);
    //void writeBooklet(const char *filename, struct QuestionBank *bank);
    struct QuestionBank bank;
    int n;
    int m;
    readQuestions("sampleFile.txt", &bank);
    //printQuestions(&bank); //DEBUG
    //writeBooklet("booklet.txt", &bank); //DEBUG
    printf("Enter number of booklets to generate: ");
    scanf("%d", &m);
    printf("Enter number of questions per booklet: ");
    scanf("%d", &n);
    for (int i = 1; i <= m; i++) {
        shuffleBank(&bank);
        generateBooklet(&bank, n,i);
    }
}

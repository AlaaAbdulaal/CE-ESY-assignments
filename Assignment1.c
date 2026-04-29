#include <stdio.h>

#define SIZE 10

struct CircularBuffer {
    char buffer[SIZE];
    int head;
    int tail;
    int count;
};

void init(struct CircularBuffer *cb) {
    (*cb).head = 0;
    (*cb).tail = 0;
    (*cb).count = 0;
}

int isFull(struct CircularBuffer *cb) {
    return ((*cb).count == SIZE);
}

int isEmpty(struct CircularBuffer *cb) {
    return ((*cb).count == 0);
}

void write(struct CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("\nBuffer Overflow\n");
    } else {
        (*cb).buffer[(*cb).tail] = data;
        (*cb).tail = ((*cb).tail + 1) % SIZE;
        (*cb).count++;
    }
}

char read(struct CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("\nBuffer Underflow\n");
        return '\0';
    } else {
        char data = (*cb).buffer[(*cb).head];
        (*cb).head = ((*cb).head + 1) % SIZE;
        (*cb).count--;
        return data;
    }
}

int main() {
    struct CircularBuffer cb;
    init(&cb);

    char name[100];
    printf("Enter your name: ");
    scanf("%s", name);

    int i = 0;
    while (name[i] != '\0') {
        i++;
    }
    
    char suffix[] = "CE-ESY";
    int k = 0;
    while (suffix[k] != '\0') {
        name[i] = suffix[k];
        i++;
        k++;
    }
    name[i] = '\0';

    for (int j = 0; name[j] != '\0'; j++) {
        write(&cb, name[j]);
    }

    printf("Output from buffer: ");
    while (!isEmpty(&cb)) {
        char c = read(&cb);
        if (c != '\0') {
            printf("%c", c);
        }
    }

    printf("\n");
    return 0;
}

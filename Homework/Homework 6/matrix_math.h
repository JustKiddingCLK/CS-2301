struct matrix {
    int size;
    float* data;
};

struct matrix* readMatrix(char* filename);
int deleteMatrix(struct matrix* A);
struct matrix* addition(struct matrix* A, struct matrix* B);
struct matrix* subtraction(struct matrix* A, struct matrix* B);


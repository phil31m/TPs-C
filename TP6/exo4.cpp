#include <iostream>
#include <memory>

using namespace std;

struct MemoryBlock {
    int size;
    MemoryBlock(int s) : size(s) {}
};

unique_ptr<MemoryBlock> merge(unique_ptr<MemoryBlock> a, unique_ptr<MemoryBlock> b) {
    if (!a || !b) return nullptr;
    int combined = a->size + b->size;
    return make_unique<MemoryBlock>(combined);
}

int main() {
    auto block1 = make_unique<MemoryBlock>(100);
    cout << "Bloc de mémoire alloué de " << block1->size << " unités." << endl;

    auto block2 = make_unique<MemoryBlock>(200);
    cout << "Bloc de mémoire alloué de " << block2->size << " unités." << endl;

    auto merged = merge(move(block1), move(block2));
    if (merged) {
        cout << "Fusion des deux blocs : " << merged->size << " unités." << endl;
    }

    cout << "Libération de la mémoire." << endl;
    return 0;
}
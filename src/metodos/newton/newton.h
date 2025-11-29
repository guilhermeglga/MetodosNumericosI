
#include <vector>

class Function{};

class Newton{
    public:
        Newton(Function f_);

        float iterar();

        int get_iteracao_atual();

    private:
        Function f;
        std::vector<float> iteracoes;
        int iteracao_atual;
};
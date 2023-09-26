#include <iostream>
#include <thread>

class DivisiveisThread {
public:
    DivisiveisThread(const std::string& nome, int valorInicial, int valorFinal)
        : nome(nome), valorInicial(valorInicial), valorFinal(valorFinal) {}

    void operator()() {
        std::cout << "Thread " << nome << " iniciada" << std::endl;
        for (int num = valorInicial; num <= valorFinal; ++num) {
            if (num % 3 == 0 && num % 5 == 0) {
                std::cout << "Thread " << nome << ": " << num << std::endl;
            }
        }
        std::cout << "Thread " << nome << " concluída" << std::endl;
    }

private:
    std::string nome;
    int valorInicial;
    int valorFinal;
};

int main() {
    // Criar as três threads com os intervalos especificados
    DivisiveisThread thread1("Thread 1", 100, 300);
    DivisiveisThread thread2("Thread 2", 301, 500);
    DivisiveisThread thread3("Thread 3", 501, 700);

    // Iniciar as threads
    std::thread t1(thread1);
    std::thread t2(thread2);
    std::thread t3(thread3);

    // Aguardar até que todas as threads terminem
    t1.join();
    t2.join();
    t3.join();

    std::cout << "Programa principal concluído" << std::endl;

    return 0;
}

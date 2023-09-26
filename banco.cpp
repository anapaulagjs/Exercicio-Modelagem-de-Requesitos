#include <iostream>
#include <vector>
#include <string>

class Cliente {
private:
    std::string nome;
    bool ativo;

public:
    Cliente(std::string nome) : nome(nome), ativo(true) {}

    void tornarInativo() {
        ativo = false;
    }

    bool estaAtivo() {
        return ativo;
    }
};

class Conta {
private:
    Cliente* cliente;
    double saldo;
    std::vector<std::string> historico;

public:
    Conta(Cliente* cliente) : cliente(cliente), saldo(0.0) {}

    void depositar(double valor) {
        saldo += valor;
        historico.push_back("Depósito de " + std::to_string(valor));
    }

    bool sacar(double valor) {
        if (saldo >= valor) {
            saldo -= valor;
            historico.push_back("Saque de " + std::to_string(valor));
            return true;
        }
        return false;
    }

    double getSaldo() {
        return saldo;
    }

    std::vector<std::string> getHistorico() {
        return historico;
    }
};

int main() {
    Cliente cliente("João");
    Conta conta(&cliente);

    conta.depositar(1000.0);
    conta.sacar(500.0);

    std::cout << "Saldo atual: " << conta.getSaldo() << std::endl;

    std::vector<std::string> historico = conta.getHistorico();
    std::cout << "Histórico de movimentação:" << std::endl;
    for (const std::string& entrada : historico) {
        std::cout << entrada << std::endl;
    }

    return 0;
}

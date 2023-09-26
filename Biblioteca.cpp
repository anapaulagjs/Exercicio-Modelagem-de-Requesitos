#include <iostream>
#include <vector>
#include <string>

class Material {
public:
    std::string titulo;
    std::string tipo;

    Material(std::string titulo, std::string tipo) : titulo(titulo), tipo(tipo) {}
};

class Usuario {
public:
    std::string nome;
    std::string tipo;

    Usuario(std::string nome, std::string tipo) : nome(nome), tipo(tipo) {}
};

class Biblioteca {
private:
    std::vector<Material> acervo;
    std::vector<Usuario> usuarios;

public:
    void cadastrarMaterial(Material material) {
        acervo.push_back(material);
    }

    void cadastrarUsuario(Usuario usuario) {
        usuarios.push_back(usuario);
    }

    void pesquisarMaterial(std::string termo) {
        for (const Material& material : acervo) {
            if (material.titulo.find(termo) != std::string::npos) {
                std::cout << "Material encontrado: " << material.titulo << " (Tipo: " << material.tipo << ")" << std::endl;
            }
        }
    }

    void renovarEmprestimo() {
        // Lógica para renovar empréstimo
    }

    void reservarMaterial() {
        // Lógica para reservar material
    }

    void solicitarCompraLivro() {
        // Lógica para solicitar compra de livro
    }

    void solicitarAssinaturaPeriodico() {
        // Lógica para solicitar assinatura de periódico
    }
};

int main() {
    Biblioteca biblioteca;

    Material livro1("Aventuras de Sherlock Holmes", "Livro");
    Material revista1("Revista de Ciência", "Revista");
    Usuario aluno1("João", "Aluno");
    Usuario funcionario1("Maria", "Funcionário");

    biblioteca.cadastrarMaterial(livro1);
    biblioteca.cadastrarMaterial(revista1);
    biblioteca.cadastrarUsuario(aluno1);
    biblioteca.cadastrarUsuario(funcionario1);

    std::cout << "Pesquisar material: " << std::endl;
    biblioteca.pesquisarMaterial("Sherlock Holmes");

    // Outras operações podem ser realizadas aqui

    return 0;
}

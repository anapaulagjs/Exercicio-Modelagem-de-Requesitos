#include <iostream>
#include <vector>
#include <string>

class Disciplina {
public:
    std::string nome;
    int cargaHoraria;
    int creditos;
    std::string ementa;
    std::vector<std::string> preRequisitos;

    Disciplina(std::string nome, int cargaHoraria, int creditos, std::string ementa) 
        : nome(nome), cargaHoraria(cargaHoraria), creditos(creditos), ementa(ementa) {}
};

class Aluno {
public:
    std::string nome;
    int matricula;
    std::vector<std::string> disciplinasMatriculadas;

    Aluno(std::string nome, int matricula) : nome(nome), matricula(matricula) {}

    void matricular(Disciplina disciplina) {
        disciplinasMatriculadas.push_back(disciplina.nome);
    }

    void cancelarMatricula(std::string nomeDisciplina) {
        // Lógica para cancelar a matrícula
    }

    void visualizarNotas() {
        // Lógica para visualizar notas
    }
};

class Professor {
public:
    std::string nome;
    std::vector<std::string> disciplinasLecionadas;

    Professor(std::string nome) : nome(nome) {}

    void lancarNotas(std::string nomeDisciplina, int matriculaAluno, double nota) {
        // Lógica para lançar notas
    }
};

int main() {
    Disciplina matematica("Matemática", 60, 4, "Cálculo, Álgebra Linear");
    Aluno aluno("João", 12345);
    Professor professor("Maria");

    aluno.matricular(matematica);
    professor.lancarNotas("Matemática", aluno.matricula, 9.0);

    std::cout << "Disciplinas matriculadas por " << aluno.nome << ":" << std::endl;
    for (const std::string& disciplina : aluno.disciplinasMatriculadas) {
        std::cout << "- " << disciplina << std::endl;
    }

    // Outras operações podem ser realizadas aqui

    return 0;
}

#include <iostream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <thread>

void Spinner(int segundos) {
    const char frames[] = {'|', '/', '-', '\\'};
    int i = 0;

    auto inicio = std::chrono::steady_clock::now();

    while (true) {
        auto agora = std::chrono::steady_clock::now();
        auto tempo = std::chrono::duration_cast<std::chrono::seconds>(agora - inicio).count();

        if (tempo >= segundos) break;

        std::cout << "\r" << frames[i % 4] << std::flush;
        i++;

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << "\r " << std::endl; // limpa o spinner
}

void falar(std::string texto) {
    std::string comando = std::string("espeak -v pt-br ") + "\"" + texto + "\"";
    std::cout << texto << std::endl;
    std::system(comando.c_str());
}

void checarpkgfala() {
    int resultado = system("espeak --version");

    if (resultado == 0) {
        falar("tudo esta funcionando");
    } else {
        std::cout << "preparando ambiente" << std::endl;
        system("pkg install espeak -y");
    }
}

int main() {

    std::string meunome = "";
    std::string comando = "";

    checarpkgfala();
    falar("assistente de terminal executado");

    while (true) {
        system("clear");    
        falar("digite um comando:");
        std::getline(std::cin, comando);

        if (comando == "oi") {
            falar("oi como vai " + meunome);
        }

        else if (comando.find("nome") != std::string::npos) {
            falar("se voce quer saber meu nome eu sou o termdroid qual o seu nome?");
            std::getline(std::cin, meunome);
            falar("que legal seu nome " + meunome);
        }

        else if (comando == "quem te criou?") {
            falar("eu fui criado por arthur santos louro");
        }

        else if (comando == "voce pode ser ilegal?") {
            falar("posso demais");
        }

        else if (comando == "voce pode executar comandos direto no terminal?") {
            falar("sim eu posso " + meunome + ", voce pode me dizer pra executar algum comando tipo listar");
        }

        else if (comando == "listar") {
            system("ls");
            std::cin.get(); //pausa
        }

        else if (comando == "qual lang foi usada pra te criar") {
            falar("eu fui criado em c++ uma lang otima");
        }

        else if (comando == "instalar c++") {
            falar("instalando c++ pode demorar aguarde");
            system("pkg install clang -y");
        }
    


        else if (comando == "root") {
            falar("root reiniciando dispositivo");
            Spinner(8);
            falar("era pegadinha ");
        
            
        }






        else if (comando == "abrir youtube") {
            falar("abrindo youtube");
            system("am start -n com.google.android.youtube/com.google.android.youtube.HomeActivity");


        }



        else if (comando == "quem sou eu") {
            falar("nao te conheco direito mais sei seu nome" + meunome);
        }




        else if (comando == "")




        else {
            falar("comando invalido");
        }









    }

    return 0;
}

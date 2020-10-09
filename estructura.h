#include <fstream>


class libreria{
private:
    struct libros{
    int num;
    std::string titulo;
    std::string autor;
    std::string editorial;
};
public:

    void leer();
    void escribir();
    void menu();
    void buscar();
//    bool abrir(fstream);
  //  bool final();
};

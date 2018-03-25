//
// Created by mkajdak on 16.11.17.
//
#include "../inc/Base.hh"


/*
 *  Konstruktor
 *      otwiera folder "baza" i plik "save"
 *      jesli nie istnieje plik baza to kontruktor nie moze zostac wywolany
 *
 */

Base::Base() {
    //Sprawdzanie czy jest co wczytac
    std::unique_ptr<fs::path> ptr{new fs::path{"baza"}};
    if (!fs::is_directory(*ptr)) return;
    if (fs::is_empty(*ptr)) {
        this->Amount_of_Questions = 0;
        return;
    }


    std::ifstream Strm;
    std::string Buf;

    Strm.open("save.txt");
    if (Strm.good()) {

        //zmienne do dzialan na pliku dlatego nie definiowane wczesniej
        size_t FirstBegin = 0;
        size_t SecondBegin, Dot, SecondEnd;
        std::string QuestionsNR, AmountOfRepeats;
        std::getline(Strm, Buf);
        /*************************seeking***********************************/
        while (!Strm.eof()) {
            //musze znalezc charakterystyczne znaki
//            FirstEnd = Buf.find_first_of(']');
            SecondBegin = Buf.find_last_of('[');
            SecondEnd = Buf.find_last_of(']');
            Dot = Buf.find_first_of('.');

            QuestionsNR = std::string(FirstBegin+1,Dot);
            AmountOfRepeats = std::string(SecondBegin,SecondEnd);


        }
    }


}

Base *Base::init() {

    if(!s_instance){
        s_instance=new Base();
    }
    return nullptr;
}


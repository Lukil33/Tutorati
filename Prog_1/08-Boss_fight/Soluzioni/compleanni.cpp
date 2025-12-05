#include <iostream>
using namespace std;

struct day{
    int num_giorno;
    int num_compleanni;
    day* next;
};

struct month{
    int num_mese;
    month* next_month;
    day* days;
};

day* generate_day(int num_mese, int num_day = 1){ // Genera la lista dei giorni di un mese
    day* giorno = new day{num_day, 0, nullptr};

    bool isFeb = (num_mese == 2);
    bool is30 = (num_mese == 4 || num_mese == 6 || num_mese == 9 || num_mese == 11);

    // Condizioni di fine
    if ((isFeb && num_day == 28) ||
        (is30  && num_day == 30) ||
        (num_day == 31)) 
    {
        return giorno;
    }

    giorno->next = generate_day(num_mese, num_day + 1);
    return giorno;
}
month* crea_calendario(int num_mese = 1){ // Genera ricorsivamente i 12 mesi
    month* mese = new month{num_mese, nullptr, generate_day(num_mese)};
    if (num_mese < 12)
        mese->next_month = crea_calendario(num_mese + 1);
    return mese;
}

void stampa_giorni(day* giorni){ // Stampa i giorni con i compleanni relativi
    day* g = giorni;
    while (g != nullptr){
        cout << "  Giorno " << g->num_giorno 
             << " -> compleanni: " << g->num_compleanni << "\n";
        g = g->next;
    }
}
void stampa_calendario(month* calendario){ // Stampa l'intero calendario mese per mese
    month* m = calendario;
    while (m != nullptr){
        cout << "=== Mese " << m->num_mese << " ===\n";
        stampa_giorni(m->days);
        cout << endl;
        m = m->next_month;
    }
}

void add_compleanno(month* calendario, int mese, int giorno){ // Aggiunge un compleanno in un giorno e mese validi
    // Controllo mese
    if (mese < 1 || mese > 12){
        cout << "[ERRORE] Mese non valido!\n";
        return;
    }

    // Trova mese
    month* m = calendario;
    while (m && m->num_mese != mese)
        m = m->next_month;

    if (!m){
        cout << "[ERRORE] Mese non trovato!\n";
        return;
    }

    // Trova giorno
    day* d = m->days;
    while (d && d->num_giorno != giorno)
        d = d->next;

    if (!d){
        cout << "[ERRORE] Giorno non valido per il mese!\n";
        return;
    }

    // Incrementa compleanni
    d->num_compleanni++;
}

void elimina_giorni(day* giorni){ // Distrugge ricorsivamente la lista dei giorni
    if (giorni != nullptr){
        elimina_giorni(giorni->next);
        delete giorni;
    }
}
void elimina_calendario(month* calendario){ // Distrugge l'intero calendario (mesi + giorni)
    if(calendario != nullptr){
        elimina_calendario(calendario->next_month);
        elimina_giorni(calendario->days);
        delete calendario;
    }
}

int main() {
    month* calendario = crea_calendario();

    add_compleanno(calendario, 12, 1);
    add_compleanno(calendario, 3, 15);
    add_compleanno(calendario, 3, 15);
    add_compleanno(calendario, 2, 29); // Errore gestito correttamente

    stampa_calendario(calendario);

    elimina_calendario(calendario);
    return 0;
}

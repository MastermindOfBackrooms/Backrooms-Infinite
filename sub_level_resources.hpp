#pragma once
#include <map>
#include <vector>
#include <string>
using namespace std;

namespace SubLevelResources {
    struct ItemData {
        string name;
        string description;
        bool usable;
        int sanityEffect;
        int hungerEffect;
    };

    struct RoomData {
        string name;
        vector<string> descriptions;
        vector<string> firstTimeDescriptions;
        vector<string> events;
        bool isDark;
        bool isHazardous;
        map<string, string> connections;
    };

    const int MAX_SANITY = 100;
    const int MAX_HUNGER = 100;
    const int SANITY_WARNING_THRESHOLD = 30;
    const int HUNGER_WARNING_THRESHOLD = 20;

    const map<string, RoomData> ROOMS = {
        {"entrance", {
            "Ingresso del Sub-Level",
            {
                "Un vasto atrio sovietico con soffitti che si perdono nell'oscurità. L'aria è densa di particelle di ruggine.",
                "Le pareti sono ricoperte di scritte cirillice sbiadite e poster di propaganda industriale in decomposizione.",
                "Un banco accettazione abbandonato domina il centro, coperto di documenti ingialliti e registri dimenticati.",
                "L'illuminazione proviene da vecchie lampade fluorescenti che sfarfallano in modo irregolare.",
                "Enormi colonne di cemento sostengono il soffitto, ognuna decorata con bassorilievi sovietici corrosi.",
                "Il pavimento in marmo screpolato riflette le luci in modo innaturale, creando illusioni di movimento."
            },
            {
                "Ti ritrovi improvvisamente in quello che sembra essere l'ingresso di un complesso industriale sovietico.",
                "Il silenzio è rotto solo dal ronzio elettrico delle luci e dal costante gocciolio di acqua nera.",
                "Un odore di ozono e metallo arrugginito permea l'aria.",
                "Una sensazione di essere osservato ti pervade immediatamente."
            },
            {
                "Un telefono sovietico sul banco inizia a squillare...",
                "Le luci si abbassano momentaneamente, rivelando ombre impossibili.",
                "Un altoparlante gracchia un messaggio incomprensibile in russo.",
                "I poster sulla parete cambiano espressione quando li guardi direttamente."
            },
            false,
            false,
            {{"nord", "corridoio"}, {"est", "spogliatoio"}}
        }},
        
        {"corridoio", {
            "Corridoio Principale",
            {
                "Un lungo corridoio che sembra distorcersi mentre lo percorri. Le pareti sono coperte di tubi industriali.",
                "Porte numerate in cirillico si susseguono su entrambi i lati, alcune sigillate con catene arrugginite.",
                "Il pavimento è un mosaico di linoleum screpolato, con strane impronte che appaiono e scompaiono.",
                "L'eco dei tuoi passi ritorna distorto, come se qualcuno ti stesse seguendo a distanza.",
                "Cavi elettrici scoperti pendono dal soffitto, emanando scintille blu occasionali.",
                "Vecchie targhe informative mostrano mappe del complesso che cambiano ogni volta che le guardi."
            },
            {
                "Il corridoio si estende come le fauci di un mostro meccanico.",
                "Le luci fluorescenti creano ombre che danzano sulle pareti umide.",
                "Un rumore meccanico costante proviene da qualche parte in profondità.",
                "L'aria diventa più densa e difficile da respirare man mano che avanzi."
            },
            {
                "Un carrello ospedaliero attraversa il corridoio da solo.",
                "Le luci iniziano a spegnersi una dopo l'altra dietro di te.",
                "Un altoparlante trasmette una ninna nanna sovietica distorta.",
                "Una figura in camice bianco sparisce dietro un angolo."
            },
            false,
            true,
            {{"sud", "entrance"}, {"nord", "sala_macchine"}, {"est", "archivio"}}
        }},

        {"sala_macchine", {
            "Sala Macchine",
            {
                "Una vasta sala piena di macchinari industriali sovietici ancora in funzione.",
                "Giganteschi ingranaggi si muovono senza scopo, macinando il vuoto.",
                "Vapore rossastro fuoriesce da tubi corrosi, formando figure nella foschia.",
                "Monitor CRT lampeggiano con dati incomprensibili e avvertimenti in russo.",
                "Pannelli di controllo emettono segnali acustici in sequenze ipnotiche.",
                "Scale metalliche portano a passerelle superiori che si perdono nell'oscurità."
            },
            {
                "Il calore è opprimente. I macchinari sembrano pulsare come organi meccanici.",
                "Rumori di pistoni e ingranaggi formano una sinfonia industriale inquietante.",
                "Qualcosa di grande si muove tra le ombre dei macchinari.",
                "Un odore di olio bruciato e ozono riempie i tuoi polmoni."
            },
            {
                "Un macchinario si avvia improvvisamente da solo.",
                "Una valvola esplode, rilasciando vapore bollente.",
                "Gli ingranaggi cambiano direzione, producendo un suono straziante.",
                "Una forma metallica si assembla da sola nell'ombra."
            },
            true,
            true,
            {{"sud", "corridoio"}, {"est", "laboratorio"}}
        }},

        {"laboratorio", {
            "Laboratorio Segreto",
            {
                "Un laboratorio pieno di strumentazione medica e scientifica sovietica.",
                "Contenitori di vetro lungo le pareti conservano forme organiche impossibili.",
                "Documenti classificati ricoprono i tavoli, macchiati di sostanze sconosciute.",
                "Computer mainframe elaborano dati infiniti su nastri magnetici.",
                "Lavagne sono coperte di equazioni che sembrano cambiare quando non le guardi.",
                "Strumenti chirurgici arrugginiti sono disposti in pattern ritualistici."
            },
            {
                "L'aria è densa di un odore chimico dolciastro.",
                "Le luci ultraviolette rivelano scritte nascoste sulle pareti.",
                "Strani suoni provengono dai contenitori sigillati.",
                "Un ronzio a bassa frequenza fa vibrare il tuo cranio."
            },
            {
                "Un contenitore si incrina, rilasciando un gas verdastro.",
                "I computer iniziano a stampare risultati di esperimenti impossibili.",
                "Una forma nei contenitori si muove, seguendoti con occhi luminosi.",
                "Le tue impronte lasciano scie fosforescenti sul pavimento."
            },
            false,
            true,
            {{"ovest", "sala_macchine"}, {"nord", "archivio"}}
        }},

        {"archivio", {
            "Archivio Documenti",
            {
                "Infinite file di scaffalature metalliche si estendono in tutte le direzioni.",
                "Documenti classificati e foto di esperimenti riempiono ogni scaffale.",
                "Vecchi terminali di consultazione emanano una luce verdastra.",
                "Il pavimento è coperto di fogli con formule matematiche impossibili.",
                "Mappe del complesso mostrano piani e livelli che non dovrebbero esistere.",
                "Schedari numerati contengono rapporti su incidenti inspiegabili."
            },
            {
                "La polvere nell'aria forma pattern ipnotici nella luce fioca.",
                "Il silenzio è interrotto solo dal fruscio di carta che si muove da sola.",
                "Senti il peso di decenni di segreti sepolti in questo luogo.",
                "Un odore di carta vecchia e inchiostro metallico permea l'aria."
            },
            {
                "Un fascicolo cade da solo da uno scaffale.",
                "Le luci dei terminali formano sequenze di codice binario.",
                "Vedi te stesso in una vecchia foto datata 1973.",
                "I documenti si riorganizzano da soli quando non guardi."
            },
            true,
            false,
            {{"sud", "laboratorio"}, {"ovest", "corridoio"}}
        }},

        {"spogliatoio", {
            "Spogliatoio del Personale",
            {
                "File di armadietti metallici si estendono in un labirinto infinito.",
                "Specchi incrinati riflettono versioni distorte della realtà.",
                "Panche di legno marcio sono coperte di uniformi abbandonate.",
                "Docce arrugginite gocciolano un liquido nero costantemente.",
                "Poster di sicurezza sovietici mostrano procedure di decontaminazione.",
                "Scarpe di lavoro formano pile disordinate, alcune ancora con tracce dei proprietari."
            },
            {
                "L'aria è satura di umidità e odore di metallo bagnato.",
                "Gli specchi sembrano riflettere momenti del passato.",
                "Sussurri echeggianti rimbalzano tra gli armadietti.",
                "Senti il peso di centinaia di storie personali interrotte."
            },
            {
                "Un armadietto si apre da solo, rivelando contenuti impossibili.",
                "Una doccia si attiva, rilasciando vapore rossastro.",
                "Vedi una figura in uniforme che sparisce dietro gli armadietti.",
                "Gli specchi mostrano un riflesso che si muove in modo indipendente."
            },
            true,
            true,
            {{"ovest", "entrance"}, {"nord", "docce"}}
        }}
    };

    const vector<string> RANDOM_EVENTS = {
        "Un pianto di bambino echeggia attraverso i corridoi, diventando una risata metallica.",
        "Le luci si spengono in sequenza, creando un'onda di oscurità.",
        "Una radio nascosta trasmette codice morse: 'TUTTI I SOGGETTI DEVONO TORNARE'.",
        "Una figura in camice bianco attraversa rapidamente il corridoio.",
        "Gli altoparlanti gracchiano: 'Attenzione compagno, sei ancora nel protocollo...'",
        "Le pareti sembrano respirare, pulsando lentamente.",
        "Senti passi metallici che ti seguono, ma non c'è nessuno.",
        "Un telefono sovietico inizia a squillare in lontananza.",
        "Le luci formano pattern che ipnotizzano chi li guarda troppo a lungo.",
        "Una porta si apre e si chiude da sola ripetutamente.",
        "Vedi la tua ombra muoversi in modo indipendente.",
        "Un carrello medico attraversa il corridoio spinto da mani invisibili.",
        "I tubi nelle pareti iniziano a pulsare come vene.",
        "Una voce familiare ti chiama da una stanza vuota.",
        "Gli orologi sulla parete iniziano a girare all'indietro."
    };

    const map<string, ItemData> ITEMS = {
        {"torcia", {"Torcia militare sovietica", "Una robusta torcia militare. Il fascio di luce sembra solido.", true, 5, 0}},
        {"lattina", {"Lattina di cibo", "Una lattina di cibo militare sovietico ancora sigillata.", true, 0, 30}},
        {"documento", {"Documento classificato", "File con dettagli inquietanti sugli esperimenti.", false, -10, 0}},
        {"chiave_rossa", {"Chiave rossa", "Una chiave di sicurezza con marcature rosse.", true, 0, 0}},
        {"medikit", {"Kit medico sovietico", "Un kit di pronto soccorso militare.", true, 20, 0}},
        {"radio", {"Radio portatile", "Una radio che capta strane frequenze.", true, -5, 0}},
        {"bussola", {"Bussola rotta", "L'ago gira costantemente in direzioni impossibili.", false, -5, 0}},
        {"diario", {"Diario personale", "Annotazioni di un ricercatore scomparso.", false, -15, 0}},
        {"pillole", {"Pillole sperimentali", "Capsule con strane marcature cirillice.", true, 15, 5}},
        {"maschera", {"Maschera antigas", "Protegge da gas tossici, ma sussurra cose.", true, 10, 0}}
    };

    const map<string, vector<string>> ENTITY_DIALOGUES = {
        {"ombra", {
            "Ti stavamo aspettando...",
            "Soggetto identificato. Iniziare protocollo.",
            "Non puoi uscire. Nessuno esce.",
            "Il ciclo deve continuare.",
            "Sei sempre stato qui.",
            "Ricordi cosa ti hanno fatto?",
            "La convergenza è vicina."
        }},
        {"scienziato", {
            "I calcoli erano corretti. La convergenza è iniziata.",
            "Soggetto [REDATTO] mostra segni di consapevolezza.",
            "Il protocollo deve continuare. Non importa il costo.",
            "Le barriere dimensionali si stanno assottigliando.",
            "Non guardare troppo a lungo le ombre.",
            "Il tempo qui non è lineare.",
            "Alcuni soggetti sono ancora nei muri."
        }}
    };

    const map<string, vector<string>> WEATHER_EFFECTS = {
        {"nebbia", {
            "Una densa nebbia rossastra riempie il corridoio.",
            "La condensa forma pattern ipnotici sulle pareti.",
            "Figure si muovono nella foschia.",
            "La nebbia sembra reagire ai tuoi movimenti.",
            "Volti si formano e dissolvono nel vapore."
        }},
        {"elettricità", {
            "Scariche elettriche danzano tra i macchinari.",
            "L'aria crepita di energia statica.",
            "Le luci pulsano in sincrono con i tuoi battiti.",
            "Archi elettrici formano simboli nell'aria.",
            "I dispositivi elettrici si attivano al tuo passaggio."
        }},
        {"radiazioni", {
            "Il contatore Geiger impazzisce.",
            "L'aria diventa pesante e metallica.",
            "Strane aurore danzano nell'aria.",
            "I metalli sembrano cambiare colore.",
            "Senti un formicolio sulla pelle."
        }}
    };
    const map<int, vector<string>> SANITY_EFFECTS = {
        {75, {
            "Le ombre iniziano a muoversi agli angoli della tua visione.",
            "Senti sussurri appena percettibili.",
            "Il tempo sembra rallentare occasionalmente.",
            "Gli oggetti sembrano vibrare leggermente.",
            "Le scritte sulle pareti cambiano quando le riguardi."
        }},
        {50, {
            "Le pareti sembrano respirare.",
            "I tuoi riflessi negli specchi si muovono in ritardo.",
            "Senti risate di bambini nelle tubature.",
            "Il pavimento sembra inclinarsi da solo.",
            "Le luci formano pattern ipnotici."
        }},
        {25, {
            "La realtà si distorce visibilmente intorno a te.",
            "Le voci nella tua testa diventano più forti.",
            "Vedi figure impossibili che ti osservano.",
            "Il tempo non scorre più in modo lineare.",
            "I tuoi ricordi si mescolano con quelli di altri."
        }}
    };

    const vector<string> hiddenDocuments = {
        "Rapporto 1973: 'Il soggetto mostra segni di dissociazione temporale'",
        "Nota personale: 'Le pareti si muovono quando nessuno guarda'",
        "Diario: 'Giorno 234 - Ho visto me stesso nel corridoio B'",
        "Telegramma: 'CHIUDERE TUTTO. SIGILLARE IL LIVELLO. ПРОТОКОЛ-7'",
        "Rapporto Incidente: 'La convergenza dimensionale è irreversibile'",
        "Nota Laboratorio: 'I soggetti mostrano segni di fusione con l'ambiente'",
        "Memo: 'Non guardare gli specchi per più di 5 secondi'",
        "File Personale: 'Il Dr. [REDATTO] è diventato parte dell'esperimento'",
        "Registro: 'Le leggi della fisica non si applicano oltre il livello 15'",
        "Ultimo Messaggio: 'Siamo sempre stati parte delle pareti'"
    };
}

# MOST - Mobilny Otwarty System Trakcyjny ♿⚡

[![License: CC BY-NC 4.0](https://img.shields.io/badge/License-CC%20BY--NC%204.0-lightgrey.svg)](https://creativecommons.org/licenses/by-nc/4.0/)
[![Hardware: Open Source](https://img.shields.io/badge/Hardware-Open%20Source-blue.svg)](#)
[![Status: Prototyp (Solve For Tomorrow)](https://img.shields.io/badge/Status-Finał_SFT_2026-brightgreen.svg)](#)

![MOST Hero Image](Grafiki/IMG_7794.JPG)

**MOST** to innowacyjna, autonomiczna przystawka z napędem elektrycznym, zaprojektowana z myślą o użytkownikach wózków o napędzie ręcznym oraz seniorach. Projekt łączy inżynierię mechaniczną, świadomy upcykling oraz technologie Internetu Rzeczy (IoT), aby skutecznie i tanio likwidować bariery architektoniczne.

Projekt został stworzony przez koło naukowe **Banach Impact Lab** z Technikum Nr 2 w Jarosławiu i jest finalistą 5. edycji programu **Samsung Solve for Tomorrow**.


## 💡 Funkcje i Innowacje
- **Autorski Mechanizm Zapadkowy:** Pozwala na bezpieczne uniesienie przednich kół wózka o 5 cm, ułatwiając pokonywanie krawężników.
- **Smart IoT & "Peace of Mind":** Wbudowany moduł Arduino z nakładką A-GSM II automatycznie wysyła alerty SMS do opiekuna (np. w przypadku niskiego stanu baterii). Wbudowany lokalizator **Samsung SmartTag** zapewnia geolokalizację wózka w czasie rzeczywistym.
- **Świadomy Upcykling:** System napędowy (silnik 500W, bateria 36V) oraz stal konstrukcyjna mogą zostać bezpiecznie pozyskane ze złomowanych hulajnóg i rynków wtórnych, drastycznie obniżając koszty.
- **Bezpieczeństwo i Ergonomia:** Wykorzystanie profesjonalnych klamer mocujących (Quick-Release) i hydraulicznych hamulców tarczowych.

## 📂 Struktura Repozytorium
To repozytorium zawiera pełną dokumentację techniczną niezbędną do zbudowania własnej przystawki MOST:

- `/Pliki źródłowe` - Pliki wymiarowe i modele 2D/3D (w tym autorska zapadka).
- `/Software` - Kod źródłowy dla mikrokontrolera Arduino (obsługa GSM i powiadomień).
- `/Elektronika` - Schematy połączeń elektrycznych, rozmieszczenie bezpieczników i izolacji.
- `/Dokumenty` - Kompletny E-book przewodnika projektowego, wzory umów dla wolontariuszy i karty audytu jakości.

## 🛠️ Jak zacząć?
Ponieważ linki do sklepów wygasają, a ceny ulegają zmianom, nasz kosztorys i wykaz części utrzymujemy jako żywy dokument w chmurze. 

🔗 **[Kliknij tutaj, aby otworzyć interaktywny Kosztorys i Listę Części (BOM)](https://onedrive.live.com/:x:/g/personal/a8c72138936d1922/IQA5gZ1s5hksRpFdZ_e9QULAAbSh9Taq9XuDRhbfOaSdpO0?rtime=PEGRod-f3kg&redeem=aHR0cHM6Ly8xZHJ2Lm1zL3gvYy9hOGM3MjEzODkzNmQxOTIyL0lRQTVnWjFzNWhrc1JwRmRaX2U5UVVMQUFiU2g5VGFxOVh1RFJoYmZPYVNkcE8wP2U9VXR3RW1MJmZiY2xpZD1Jd1pYaDBiZ05oWlcwQ01UQUFZbkpwWkJFeE1WSXdhMGxGZHpGRFZqWXhkazQ1Y25OeWRHTUdZWEJ3WDJsa0VESXlNakF6T1RFM09EZ3lNREE0T1RJQUFSNFBKT3oyUHplUG9kOUdTN01ZS2tzdjJsTnNneExvSVN4VlEtWWhVWnppSFpaZ21mNlFkZ1Z5aWNsdC1RX2FlbV9lOWQxQndqUnU0OHlNT3puQzk5QVFR)**

Znajdziesz tam parametrylinki do sklepów internetowych, gdzie możesz znaleźć: silnik, moduły elektroniczne, śruby, zaś w e-booku znajdziesz sugestie, które elementy można bezpiecznie pozyskać z upcyklingu. Budowa systemu MOST ze sprawnych części używanych pozwala na oszczędności rzędu nawet 80% względem rozwiązań komercyjnych.

## 🤝 Nasz Model Społeczny
MOST to nie tylko sprzęt, to innowacja społeczna. W naszym rodzimym Jarosławiu wdrożyliśmy model, w którym jako członkowie Koła Naukowego budujemy przystawki jako **wolontariusze za darmo**, a użytkownik pokrywa jedynie koszt części w ramach darowizny na rzecz Stowarzyszenia "Nauka i Rozwój".

Zachęcamy szkoły, warsztaty (MakerSpace) i inne fundacje do kopiowania tego modelu w swoich społecznościach lokalnych! W folderze `/Dokumenty` znajdziecie przygotowane przez nas wzory *Umowy Przekazania Prototypu do Testów*.

## ⚠️ Ważne: Wyłączenie Odpowiedzialności (Disclaimer)
Przystawka MOST jest rozwiązaniem badawczo-edukacyjnym typu "Zrób-to-sam" (DIY). **NIE JEST wyrobem medycznym**. Decydując się na budowę urządzenia z wykorzystaniem niniejszego repozytorium, podejmujesz prace wyłącznie na własne ryzyko. Autorzy nie ponoszą odpowiedzialności za błędy wykonawcze (w tym problemy z pakietami Li-Ion), potencjalne uszkodzenia sprzętu ani obrażenia ciała. Przed budową bezwzględnie zapoznaj się z Kartą Wywiadu i przeciwwskazaniami opisanymi w naszym e-booku.

## ⚖️ Licencja
Ten projekt jest udostępniany na licencji **Creative Commons Uznanie autorstwa – Użycie niekomercyjne 4.0 Międzynarodowe (CC BY-NC 4.0)**. 
- Możesz swobodnie korzystać z dokumentacji i modyfikować projekt.
- Zawsze musisz podać autorów oryginalnego projektu.
- **Kategoryczny zakaz komercyjnej sprzedaży urządzenia.**

Szczegóły: [LICENSE](LICENSE)

## 👥 Zespół "Banach Impact Lab"
- **Polina Horodovikova** – Design, Komunikacja i Marketing
- **Jakub Mazurkiewicz** – Inżynieria Mechaniczna i Elektryczna
- **Jakub Pyszniak** – Inżynieria Mechaniczna i Elektryczna

**Opiekunowie Merytoryczni:** mgr inż. Stanisław Pietluch, mgr inż. Mariusz Skupień

**Wsparcie Organizacyjne:** Technikum Nr 2 w Jarosławiu, Stowarzyszenie "Nauka i Rozwój"

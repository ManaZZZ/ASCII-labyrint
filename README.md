# ASCII Labyrint - Alwar

## 1. Sammanfattning
ASCII labyrint är ett textbaserat spel där en spelare ska ta sig igenom en labyrint. Spelaren kan köra antingen en campaign mode, där man ska ta sig igenom alla kartor på en viss tid eller så kan man köra och träna en karta i taget. Spelet har också en meny för att välja spelläge och en affär där spelaren kan köpa en ikon för pengar den har plockat upp under ett spel..

## 2. Bakgrund
ASCII labyrint är ett spel där spelaren måste lista ut den snabbaste vägen till målet men samtidigt plocka upp pengar och ta sig till nästa karta. När jag har skapat detta spel har jag framför allt tränat på att göra en bra spelupplevelse istället för väldigt avancerade funktioner. Det viktigaste som jag har lärt mig om är ANSI koder, hur man bakar in kod i funktioner och att kommentera min kod.

## 3. Nyckelaspekter
I början av utvecklingen så använde jag system(“cls”) för att rensa skärmen varje gång spelet uppdaterades och jag skrev ut kartan med en for-loop som skrev ut varje tecken för sig. Detta gjorde att spelet blinkade varje gång kartan uppdateras vilket var jobbigt att titta på. Jag löste detta problem genom att använda ANSI koder för att flytta tillbaka markören där text skrivs ut till början av konsolen och sedan skriva över det som redan fanns där. Jag gjorde också en text av kartan i en string och skrev ut hela stringen på en gång vilket gjorde att markören inte flög över skärmen hela tiden.

## 4. Hur används programmet
När programmet startas hamnar man i menyn. Där får du välja om du vill köra “campaign mode” där du ska ta dig igenom alla kartor på 100 sekunder. Du kan också välja att bara köra en karta i taget eller så kan du gå in i shoppen för att köpa en ny spelar ikon.

När man kommer in i spelet kan man gå runt med piltangenterna och man ska nå “E” exit för att komma till nästa karta. Man kan alltid använda knappen “e” på tangentbordet för att gå tillbaka till menyn eller “q” för att avsluta programmet.

## 5. Utmaningar
Spelet har bara ett enspelarläge och det saknar något som låt oss säga gör spelet lite spännande, exempelvis ett monster som jagar dig. Det var även svårt att få till hur en funktion skulle kunna skriva ut flera olika kartor men det löste jag med att använda en array med pekare för att peka på olika kartor.

## 6. Vad härnäst?
Det som jag helst skulle vilja lägga till var en map generator så att varje gång man spelar så skulle man inte få samma karta. Också ett flerspelarläge eller ett monster som jagade spelaren. 

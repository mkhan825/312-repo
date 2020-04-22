
Martian count(int cents) {
    Martian min;
    if(cents < 5) {
        min.dodeks = 0;
        min.nicks = 0;
        min.pennies = cents;
    }
    if(cent > 5 && cent < 12) {
        min.nicks++;
        count(cents-5);
    }
    if(cent > 12) {
        if(cent % 12 >=5 ) {
            count(cents-12);
        }
        count(cents-5);
    }
}

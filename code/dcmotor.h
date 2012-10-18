void speed(int j) {
        if(j>100) j=100;
        if(j<0) j=0;
                PORTB = 0x0c;
                for(int i=0;i!=j;i++) {
                        while(!(TIFR & (1<<TOV0)));
                        TCNT0 = 0x63;
                        TIFR |= (1<<TOV0); /* Timer restarts as soon as you configure this.
                        Hence TCNT0 must be written before TIFR */
                }
                PORTB = 0x00;
                for(int k=0;k!=100-j;k++) {
                        while(!(TIFR & (1<<TOV0)));
                        TCNT0 = 0x63;
                        TIFR |= (1<<TOV0);
                }
}

void mvfwd() {
	speed(50);
}
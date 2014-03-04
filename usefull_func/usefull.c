/*
 * usefull.c
 *
 *  Created on: Feb 21, 2014
 *      Author: ivan
 */
int int_to_bit(unsigned int b,int c){
	b=(b>>c)&1;
	return b;
}
void set_bit(int *b,int c,int set){
	if(set==1)
		*b|=(1U<<c);
	if(set==0)
		*b&=(~(1U<<c));
}

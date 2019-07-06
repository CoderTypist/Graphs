// author Christian Bargraser

#ifndef _Comparisons_h_
#define _Comparisons_h_

#define EQAUL 0
#define LESS_THAN 1
#define GREATER_THAN 2

int compareChar(void *firstValue, void *secondValue);
int compareSignedChar(void *firstValue, void *secondValue);
int compareUnsignedChar(void *firstValue, void *secondValue);
int compareShort(void *firstValue, void *secondValue);
int compareShortInt(void *firstValue, void *secondValue);
int compareSignedShort(void *firstValue, void *secondValue);
int compareSignedShortInt(void *firstValue, void *secondValue);
int compareUnsignedShort(void *firstValue, void *secondValue);
int compareUnsignedShortInt(void *firstValue, void *secondValue);
int compareInt(void *firstValue, void *secondValue);
int compareSigned(void *firstValue, void *secondValue);
int compareSignedInt(void *firstValue, void *secondValue);
int compareUnsigned(void *firstValue, void *secondValue);
int compareUnsignedInt(void *firstValue, void *secondValue);
int compareLong(void *firstValue, void *secondValue);
int compareLongInt(void *firstValue, void *secondValue);
int compareSignedLong(void *firstValue, void *secondValue);
int compareSignedLongInt(void *firstValue, void *secondValue);
int compareUnsignedLong(void *firstValue, void *secondValue);
int compareUnsignedLongInt(void *firstValue, void *secondValue);
int compareLongLong(void *firstValue, void *secondValue);
int compareLongLongInt(void *firstValue, void *secondValue);
int compareSignedLongLong(void *firstValue, void *secondValue);
int compareSignedLongLongInt(void *firstValue, void *secondValue);
int compareUnsignedLongLong(void *firstValue, void *secondValue);
int compareUnsignedLongLongInt(void *firstValue, void *secondValue);
int compareFloat(void *firstValue, void *secondValue);
int compareDouble(void *firstValue, void *secondValue);
int compareLongDouble(void *firstValue, void *secondValue);
int compareString(void *firstValue, void *secondValue);

int compareChar(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareChar(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareChar(): void *firstValue was NULL\n\n");
        return -1;
    }

    char first = *((char*)firstValue);
    char second = *((char*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareSignedChar(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareSignedChar(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareSignedChar(): void *firstValue was NULL\n\n");
        return -1;
    }

    signed char first = *((signed char*)firstValue);
    signed char second = *((signed char*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareUnsignedChar(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareUnsignedChar(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareUnsignedChar(): void *firstValue was NULL\n\n");
        return -1;
    }

    unsigned char first = *((unsigned char*)firstValue);
    unsigned char second = *((unsigned char*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareShort(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareShort(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareShort(): void *firstValue was NULL\n\n");
        return -1;
    }

    short first = *((short*)firstValue);
    short second = *((short*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareShortInt(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareShortInt(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareShortInt(): void *firstValue was NULL\n\n");
        return -1;
    }

    short int first = *((short int*)firstValue);
    short int second = *((short int*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareSignedShort(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareSignedShort(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareSignedShort(): void *firstValue was NULL\n\n");
        return -1;
    }

    signed short first = *((signed short*)firstValue);
    signed short second = *((signed short*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareSignedShortInt(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareSignedShortInt(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareSignedShortInt(): void *firstValue was NULL\n\n");
        return -1;
    }

    signed short int first = *((signed short int*)firstValue);
    signed short int second = *((signed short int*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareUnsignedShort(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareUnsignedShort(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareUnsignedShort(): void *firstValue was NULL\n\n");
        return -1;
    }

    unsigned short first = *((unsigned short*)firstValue);
    unsigned short second = *((unsigned short*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareUnsignedShortInt(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareUnsignedShortInt(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareUnsignedShortInt(): void *firstValue was NULL\n\n");
        return -1;
    }

    unsigned short int first = *((unsigned short int*)firstValue);
    unsigned short int second = *((unsigned short int*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareInt(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareInt(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareInt(): void *firstValue was NULL\n\n");
        return -1;
    }

    int first = *((int*)firstValue);
    int second = *((int*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareSigned(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareSigned(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareSigned(): void *firstValue was NULL\n\n");
        return -1;
    }

    signed first = *((signed*)firstValue);
    signed second = *((signed*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareSignedInt(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareSignedInt(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareSignedInt(): void *firstValue was NULL\n\n");
        return -1;
    }

    signed int first = *((signed int*)firstValue);
    signed int second = *((signed int*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareUnsigned(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareUnsigned(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareUnsigned(): void *firstValue was NULL\n\n");
        return -1;
    }

    unsigned first = *((unsigned*)firstValue);
    unsigned second = *((unsigned*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareUnsignedInt(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareUnsignedInt(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareUnsignedInt(): void *firstValue was NULL\n\n");
        return -1;
    }

    unsigned int first = *((unsigned int*)firstValue);
    unsigned int second = *((unsigned int*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareLong(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareLong(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareLong(): void *firstValue was NULL\n\n");
        return -1;
    }

    long first = *((long*)firstValue);
    long second = *((long*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareLongInt(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareLongInt(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareLongInt(): void *firstValue was NULL\n\n");
        return -1;
    }

    long int first = *((long int*)firstValue);
    long int second = *((long int*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareSignedLong(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareSignedLong(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareSignedLong(): void *firstValue was NULL\n\n");
        return -1;
    }

    signed long first = *((signed long*)firstValue);
    signed long second = *((signed long*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareSignedLongInt(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareSignedLongInt(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareSignedLongInt(): void *firstValue was NULL\n\n");
        return -1;
    }

    signed long int first = *((signed long int*)firstValue);
    signed long int second = *((signed long int*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareUnsignedLong(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareUnsignedLong(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareUnsignedLong(): void *firstValue was NULL\n\n");
        return -1;
    }

    unsigned long first = *((unsigned long*)firstValue);
    unsigned long second = *((unsigned long*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareUnsignedLongInt(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareUnsignedLongInt(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareUnsignedLongInt(): void *firstValue was NULL\n\n");
        return -1;
    }

    unsigned long int first = *((unsigned long int*)firstValue);
    unsigned long int second = *((unsigned long int*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareLongLong(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareLongLong(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareLongLong(): void *firstValue was NULL\n\n");
        return -1;
    }

    long long first = *((long long*)firstValue);
    long long second = *((long long*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareLongLongInt(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareLongLongInt(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareLongLongInt(): void *firstValue was NULL\n\n");
        return -1;
    }

    long long int first = *((long long int*)firstValue);
    long long int second = *((long long int*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareSignedLongLong(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareSignedLongLong(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareSignedLongLong(): void *firstValue was NULL\n\n");
        return -1;
    }

    signed long long first = *((signed long long*)firstValue);
    signed long long second = *((signed long long*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareSignedLongLongInt(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareSignedLongLongInt(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareSignedLongLongInt(): void *firstValue was NULL\n\n");
        return -1;
    }

    signed long long int first = *((signed long long int*)firstValue);
    signed long long int second = *((signed long long int*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareUnsignedLongLong(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareUnsignedLongLong(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareUnsignedLongLong(): void *firstValue was NULL\n\n");
        return -1;
    }

    unsigned long long first = *((unsigned long long*)firstValue);
    unsigned long long second = *((unsigned long long*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareUnsignedLongLongInt(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareUnsignedLongLongInt(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareUnsignedLongLongInt(): void *firstValue was NULL\n\n");
        return -1;
    }

    unsigned long long int first = *((unsigned long long int*)firstValue);
    unsigned long long int second = *((unsigned long long int*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareFloat(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareFloat(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareFloat(): void *firstValue was NULL\n\n");
        return -1;
    }

    float first = *((float*)firstValue);
    float second = *((float*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareDouble(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareDouble(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareDouble(): void *firstValue was NULL\n\n");
        return -1;
    }

    double first = *((double*)firstValue);
    double second = *((double*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareLongDouble(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareLongDouble(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareLongDouble(): void *firstValue was NULL\n\n");
        return -1;
    }

    long double first = *((long double*)firstValue);
    long double second = *((long double*)secondValue);

    if( first < second ){
        return LESS_THAN;
    }

    else if( first > second ){
        return GREATER_THAN;
    }

    return EQUAL;
}

int compareString(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: Comparisons.h: compareString(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: Comparisons.h: compareString(): void *firstValue was NULL\n\n");
        return -1;
    }
	
    char* first = firstValue;
    char* second = secondValue;

    int comparisonResult = strcmp(firstValue, secondValue);

    if( comparisonResult < 0 ){
        return LESS_THAN;
    }

    else if( comparisonResult > 0 ){
        return GREATER_THAN;
    }

    return EQUAL;
}

#endif

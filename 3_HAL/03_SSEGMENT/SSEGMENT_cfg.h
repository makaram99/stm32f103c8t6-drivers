#ifndef SSEGMENT_CFG_H   
#define SSEGMENT_CFG_H   

#define POV_ENABLE       (1U)


typedef enum COMMON_CONNECTION_t{
    COMMON_ANODE,
    COMMON_CATHODE
}COMMON_CONNECTION_t;

typedef struct SSEGMENT_CONFIGS_t{
    SSEGMENT_t              segment;
    GPIO_PIN_t              pinA;
    GPIO_PIN_t              pinB;
    GPIO_PIN_t              pinC;
    GPIO_PIN_t              pinD;
    GPIO_PIN_t              pinE;
    GPIO_PIN_t              pinF;
    GPIO_PIN_t              pinG;
    GPIO_PIN_t              pinDot;
    GPIO_PIN_t              pinEN;
    COMMON_CONNECTION_t     anodeOrCathode;
}SSEGMENT_CONFIGS_t;

extern SSEGMENT_CONFIGS_t segmentsConfigs[];
extern u8_t digitsConfigs[];
extern u8_t countSegments;
extern u8_t countDigits;


#endif                  

#include <pthread.h>

struct station {
    pthread_mutex_t lock;

    pthread_cond_t passageiros;
    pthread_cond_t embarque;

    int assentos_disponiveis;
    int passageiros_esperando;
    int passageiros_autorizados;
    int passageiros_embarcados;
};

void station_init(struct station *station)
{
    pthread_mutex_init(&station->lock, NULL);

    pthread_cond_init(&station->passageiros, NULL);
    pthread_cond_init(&station->embarque, NULL);

    station->assentos_disponiveis = 0;
    station->passageiros_esperando = 0;
    station->passageiros_autorizados = 0;
    station->passageiros_embarcados = 0;
}
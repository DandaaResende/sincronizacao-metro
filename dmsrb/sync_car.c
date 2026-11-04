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

void station_wait_for_car(struct station *station)
{
    pthread_mutex_lock(&station->lock);

    // Registra a chegada do passageiro à estação.
    station->passageiros_esperando++;

    // Aguarda enquanto não houver assentos disponíveis.
    while (station->assentos_disponiveis == 0) {
        pthread_cond_wait(&station->passageiros, &station->lock);
    }

    // Reserva um assento para o passageiro.
    station->assentos_disponiveis--;
    station->passageiros_autorizados++;

    pthread_mutex_unlock(&station->lock);
}

void station_on_board(struct station *station)
{
    pthread_mutex_lock(&station->lock);

    // Registra a confirmação do embarque.
    station->passageiros_embarcados++;

    // Informa que um passageiro terminou de embarcar.
    station->passageiros_autorizados--;

    // Avisa o carro que houve uma confirmação.
    pthread_cond_signal(&station->embarque);

    pthread_mutex_unlock(&station->lock);
}
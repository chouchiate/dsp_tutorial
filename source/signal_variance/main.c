#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define SIG_LENGTH 320

extern double InputSignal_f32_1kHz_15kHz[SIG_LENGTH];
double calc_signal_mean (double *sig_src_arr, int sig_len);
double calc_signal_variance (double *sig_src_arr, double sig_mean, int sig_len);
double MEAN;
double VARIANCE;

int main () {
  double * dPtr = &InputSignal_f32_1kHz_15kHz[0];
  MEAN = calc_signal_mean(dPtr, SIG_LENGTH);
  printf("\nMean = %f",MEAN);

  VARIANCE = calc_signal_variance(dPtr, MEAN, SIG_LENGTH);
  printf("\nVariance = %f", VARIANCE);
  
  return 0;
}

double calc_signal_mean (double *sig_src_arr, int sig_len) {
  double _mean = 0.0;
  for (int i = 0; i < sig_len; i++) {
    _mean = _mean + sig_src_arr[i];
  }

  _mean = _mean / (double) sig_len;
  return _mean;
}

double calc_signal_variance (double *sig_src_arr, double sig_mean, int sig_len) {
  double _variance = 0.0;
  for (int i = 0; i < sig_len; i++) {
    _variance = _variance + pow((sig_src_arr[i] - sig_mean), 2);

  }

  _variance = _variance / (sig_len - 1);
  
  return _variance;
}
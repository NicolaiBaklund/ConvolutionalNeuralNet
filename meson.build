project('ConvolutionalNeuralNetwork', 'cpp', default_options : ['cpp_std=c++17'])

linAlg_src = [
  'linAlg/matrix.cpp',
  'linAlg/utils.cpp',
]

executable('cnn', ['main.cpp'] + linAlg_src, include_directories: 'linAlg')
# llamas
General Purpose C++ App Creation Framework

Nothing much to see to far ... This is a pet project that should probably be private ;)

## Purpose

This framework aims to help create fast and robust applications by leveraging dependency injection and by using a Entities-Components-Systems architecture.

It also aims to be easy to use.

## Quick start


```
mkdir build
cd build
cmake ..
```

## High level architecture

TODO : Add drawing

### llama-core

* Interfaces for creating your own systems inside plugins
* Plugins discovery logic
* Objects creation, destruction & update logic
* Events system

### llama-plugin

* It's where you define your systems, entities & components to be used by Llamas.

## Available plugins

### llama-qt

Adds Qt support to Llamas. It acts as a simple wrap around Qt. It is meant to act as an example and the wrapped functionality is quite limited.
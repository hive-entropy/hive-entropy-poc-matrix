#include "../include/Server.h"

string Server::read(){

}


void Server::write(string message){

}


int Server::listen(){

}


Server::Server(std::string file) : sock(file){
    
}


void Server::run(){

}


Server::~Server(){
    delete &sock;
}
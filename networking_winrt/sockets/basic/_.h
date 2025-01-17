#pragma once

//#ifdef BSD_STYLE_SOCKETS
//#include <openssl/ssl.h>
//#endif


namespace sockets_bsd
{


   /** \defgroup basic Basic sockets */
   /** socket axis class.
   \ingroup basic */
   class CLASS_DECL_NETWORKING_BSD socket :
      virtual public base_socket
   {
   public:



      /** "Default" constructor */
      socket();

      virtual ~socket();




      /** create a socket file descriptor.
      \lparam af Address family AF_INET / AF_INET6 / ...
      \lparam type SOCK_STREAM / SOCK_DGRAM / ...
      \lparam protocol "tcp" / "udp" / ... */
      SOCKET CreateSocket(int af,int type,const string & protocol = "");



      /** close connection immediately - internal use.
      \sa SetCloseAndDelete */
      virtual void close();

      /** add file descriptor to sockethandler fd_set's. */
      void set(bool bRead,bool bWrite,bool bException = true);

      /** Returns true when socket file descriptor is valid
      and socket is not about to be closed. */
      virtual bool Ready();

      virtual bool is_valid();

      virtual int close_socket(SOCKET s);




      /** SSL; get pointer to ssl action_context structure. */
      virtual SSL_CTX *GetSslContext() { return nullptr; }
      /** SSL; get pointer to ssl structure. */
      virtual SSL *GetSsl() { return nullptr; }
      //@}


      using base_socket::SetNonblocking;
      bool SetNonblocking(bool bNb, SOCKET s);


      virtual ::networking::address get_peer_address();
      virtual ::networking::address get_socket_address();



   };


} // namespace sockets_bsd





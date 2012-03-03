
eio-simple
==========

Control libeio from javascript.

Usage
-----

`var eio = require('eio-simple');`

* `eio.setMinParallel(threads)`: Sets the available number of threads. Node's default is 4. **Use this function for increasing the number of threads.**
* `eio.setMaxParallel(threads)`: Sets the maximum number of threads. This **only** caps the number of threads and expires existing threads that are bigger than the maximum.
* `eio.setMaxIdle(threads)`: Sets the maximum number of idle threads. If more threads are idle they will automatically be stopped.
* `eio.setIdleTimeout(seconds)`: Sets the number of seconds after which a thread is marked idle.

* `eio.usage()`:
  Returns an object with thread usage information.
  * `requests` contains the number of in-flight requests.
  * `ready` contains the number of not yet handled requests.
  * `pending` contains the number of finished but unhandled requests.
  * `threads` contains the number of worker threads in use currently.

# Credits

Based on [https://github.com/developmentseed/node-eio](https://github.com/developmentseed/node-eio)


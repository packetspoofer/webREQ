<h1>Usage</h1>
Execute ./webREQ and insert in the first line the <strong>endpoint</strong> and in the second insert the <strong> query parameters</strong> for post and put requests.

<h2> Compilation (Without any optimizations)</h2>
<code>gcc main.c requests.c -lcurl -o webREQ </code>

<h2> GOALS </h2>

- [X] Check the url input (formatted as http)
- [ ] Parse the status code in string (Example: GET 200 [SUCCESS])
- [ ] Implement multiple post values
- [ ] Rewrite with --comands-args for stuff like only getting methods or only uploading methods

<h1>Usage</h1>
Execute ./webREQ and insert in the first line the <strong>endpoint</strong> and in the second insert the <strong> query parameters</strong> for post and put requests.

<h2> Compilation (Without any optimizations)</h2>
<code>gcc main.c requests.c -lcurl -o webREQ </code>


<h2> Compilation (With optimizations)</h2>
<code>gcc -O3 -march=native main.c requests.c -lcurl -o webREQ </code>

<h2> GOALS </h2>

- [X] Check the url input (formatted as http)
- [X] Parse the status code in string (Example: GET 200 [SUCCESS])
- [ ] Implement multiple post values
- [ ] Rewrite with --comands-args for stuff like only getting methods or only uploading methods

<h5> <em>Gli invidiosi diranno che è uno scanner contro l'infrastruttura</em></h5>
<img src="https://media4.giphy.com/media/v1.Y2lkPTc5MGI3NjExZHVya2VneDdxb21rbGU1NnF4aDlyb3N2ejdkYWFkMjJsOHNkYXF0byZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9cw/YOqem0DUvPvNnN8toF/giphy.gif" width="190" height="190" />

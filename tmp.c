// (!) Not real C code; just an example of the steps the developer that uses
// the framework might follow to create an endpoint

// endpoint: /users/login
// POST

// DTO
$dto(struct s_credentials, "cred") // a decorator (non-valid C code)
struct s_credentials {
    char username[16];
    char password[16];
};

/*
The object will send a JSON object.

{
    "username": "jonas",
    "password": "pass"
}
*/

$post(login, "/users/login")
bool login(Request *req, Response *res) {
    char *user, *pass;
    user = req->cred->username;
    pass = req->cred->password;

    if (!strcmp(user, "jonas")
        && !strcmp(pass, "pass")
    ) {
        req.session.loggedin = true;

        return json("{'loggedin': true}");
    }
    else {
        res.errorcode = 301;
        return httperror(res, "Unauthorized");
    }
}

// When the developer is done with this, it's not necessary to shut everything
// down and recompile the web server; the only thing needed is to run some
// command like a make build, and then the whole file will be compiled into
// a dynamically linked shared library, a .so file, and that library file
// will then be hot loaded into the main application, so directly after
// make build, no need to restart anything, no loss of data, the endpoint
// will be active

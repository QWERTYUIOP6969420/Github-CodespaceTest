

    app.use(body_parser.json());
    app.use((req, res, next) => {
        res.header('Access-Control-Allow-Origin', '*');
        next();
    });
    app.use(cors());

    const http_server = http.createServer(app);
    const db = new sqlite3.Database('./database.db', (err) => {
        if(err){
            console.error(err.message);
        }
        db.run("CREATE TABLE IF NOT EXISTS new_table(test_values TEXT(255));");
    });

    app.post('/create', (req, res) => {
        res.header('Access-Control-Allow-Origin', '*');
        db.serialize(() => {
            db.run("INSERT INTO new_table(test_values) VALUES (?)", JSON.stringify(req.body.test_values), (err) => {
                if(err){
                    console.error(err.message);
                }
                res.send(req.body.test_values);
                console.log(req.body.test_values);
            });
        });
    });

    app.get('/read_all', (req, res) => {
        res.header('Access-Control-Allow-Origin', '*');
        db.serialize(() => {
            db.all("SELECT * FROM new_table", (err, data) => {
                if(err){
                    console.error(err.message);
                }
                    res.send(data);
                    console.log(data);
            });
        });
    });

    http_server.listen(port, (err) => {
        console.log("Server listening on port " + port);
        if(err){
            console.error(err.message);
        }
    });
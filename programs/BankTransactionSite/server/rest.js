const sqlite3 = require('sqlite3');
const express = require('express');
const app = express();
const body_parser = require('body-parser');
const http = require('http');
const port = 5000;
const cors = require('cors');

app.use(body_parser.json());
app.use((req, res, next) => {
    res.header('Access-Control-Allow-Origin', '*');
    next();
});
app.use(cors());

const http_server = http.createServer(app);
const db = new sqlite3.Database('./bankInformation.db', (err) => {
    if(err){
        console.error(err.message);
    }
    db.run("CREATE TABLE IF NOT EXISTS user_data(user_id INT PRIMARY KEY, user_name TEXT(255), user_account_balance INT NOT NULL);");
})

app.post("/create_account", (req, res) => {
    res.header('Access-Control-Allow-Origin', '*');
    db.serialize(() => {
        db.run("INSERT INTO user_data(user_id, user_name, user_account_balance) VALUES (?, ?, 0);", JSON.stringify(req.body.user_id), JSON.stringify(req.body.username), (err) => {
            if(err){
                console.error(err.message);
            }
            console.log(req.body.user_id);
            console.log(req.body.username);
            console.log(req.body.user_account_balance);
            res.send([req.body.user_id, req.body.username, req.body.user_account_balance]);
        });
    });
});

app.get("/user_data", (req, res) => {
    db.serialize(() => {
        db.run("SELECT user_name, user_account_balance FROM user_data WHERE user_id = ? AND user_name = ?;", req.body.user_id, req.body.username, (err, data) => {
            if(err){
                console.error(err.message);
            }
            res.send(data);
            console.log(data);
        });
    });
});

app.patch('/change_account_balance', (req, res) => {
    db.serialize(() => {
        var id_check = db.run("SELECT * FROM user_data WHERE user_id = ?", JSON.stringify(req.body.user_id), (err) => {
            if(err){
                console.error(err.message);
            }
        });
        if(id_check == null){
            res.send("Invalid UID");
        } else {db.run("UPDATE user_data SET user_account_balance = ? WHERE user_id = ?;", JSON.stringify(req.body.username), JSON.stringify(req.body.user_account_balance), JSON.stringify(req.body.user_id),  (err) => {
            if(err){
                console.error(err.message);
            }
            res.send(req.body.username, user_account_balance);
            console.log(req.body.username);
            console.log(user_account_balance);
            });
        }
    });
});

app.patch('/change_username', (req, res) => {
    db.serialize(() => {
        var id_check = db.run("SELECT * FROM user_data WHERE user_id = ?", JSON.stringify(req.body.user_id), (err) => {
            if(err){
                console.error(err.message);
            }
        });
        if(id_check == null){
            res.send("Invalid UID");
        } else {
            db.run("UPDATE user_data SET user_name = ? WHERE user_id = ?", JSON.stringify(req.body.username), JSON.stringify(req.body.user_id), (err) => {
                if(err){
                    console.error(err.message);
                }
                res.send(req.body.username);
                console.log(req.body.username);
            });
        }
    });
});

app.post("/terminate_account", (req, res) => {
    db.serialize(() => {
        var id_check = db.run("SELECT * FROM user_data WHERE user_id = ?", JSON.stringify(req.body.user_id), (err) => {
            if(err){
                console.error(err.message);
            }
        });
        if(id_check == null){
            res.send("Invalid UID");
        } else {
            db.run("DELETE FROM user_data WHERE user_id = ?;", JSON.stringify(req.body.user_id), (err) => {
                if(err){
                    console.error(err.message);
                }
                res.send("Your account has been deleted, thank you for working with us");
                console.log("Account Deleted");
            });
        }
    });
});

http_server.listen(port, (err) => { 
    if(err){
        console.error(err.message);
    }
    console.log("Server listening on port " + port);
});
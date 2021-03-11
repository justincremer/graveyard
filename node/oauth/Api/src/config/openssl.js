const path = require("path");
const fs = require("fs");

const certs_dir = "../../../.dev/certs";
const sslKey = fs.readFileSync(path.join(__dirname, certs_dir, "key.pem"));
const sslCert = fs.readFileSync(path.join(__dirname, certs_dir, "cert.pem"));

module.exports.sslCreds = { key: sslKey, cert: sslCert };

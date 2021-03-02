const books = new Map<string, any>();

books
    .set("1", {
        id: "1",
        title: "Manufacturing Consent",
        author: "Noam Chomsky",
    })
    .set("2", {
        id: "2",
        title: "Who Rules the World",
        author: "Noam Chomsky",
    });

export default books;

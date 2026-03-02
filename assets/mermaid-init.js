
document$.subscribe(function () {
    if (typeof mermaid === "undefined") {
        return;
    }

    mermaid.initialize({
        startOnLoad: false,
        securityLevel: "loose",
        theme: document.body.getAttribute("data-md-color-scheme") === "slate" ? "dark" : "default"
    });

    mermaid.run({
        querySelector: ".mermaid"
    });
});

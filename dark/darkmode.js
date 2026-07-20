let btn = document.querySelector("button");
let body = document.querySelector("body");

btn.addEventListener("click", () => {
  if (body.classList.contains("dark")) {
    body.classList.remove("dark");
    body.classList.add("light");
    btn.innerText = "DARK";
  } else {
    body.classList.remove("light");
    body.classList.add("dark");
    btn.innerText = "LIGHT";
  }
});
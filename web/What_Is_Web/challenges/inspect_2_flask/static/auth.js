

function redirectAfterSubmit(event) {
  event.preventDefault();
  if(checkAuth()){
    window.location.href="super_secret_flag.txt";
  }
}


var checkAuth = function() {
  var user = document.getElementById("name").value;
  var pass = document.getElementById("pass").value;
  if (user == "admin" && pass == "password123") {
    return true;
  } else {
    document.getElementById("error").innerHTML='<div class="alert alert-danger"><b>ERROR:</b> Invalid password</div>';
    return false;
  }
  document.getElementById("error").innerHTML='<div class="alert alert-danger"><b>ERROR:</b> Username does not exist!</div>';
  return false;
}

